#include "PacketProcessor.h"

#include <iostream>

PacketProcessor::PacketProcessor()  {}

void PacketProcessor::ProcessPacket(const std::vector<uint8_t>&packet, int protocol)
{
    using namespace std::chrono;

    // Capture the current timestamp
    auto now = system_clock::now();
    auto now_c = system_clock::to_time_t(now);

    // Format the timestamp
    std::stringstream timestamp;
    timestamp << std::put_time(std::localtime(&now_c), "%Y-%m-%d %H:%M:%S");

    ParseEthernetHeader(packet, timestamp.str(), protocol);
}

void PacketProcessor::ParseEthernetHeader(const std::vector<uint8_t> &packet, const std::string &timestamp, int protocol)
{
    EthernetHeader* eth = reinterpret_cast<EthernetHeader*>(const_cast<uint8_t*>(packet.data()));

    uint16_t type = ntohs(eth->type);

    switch (type) {
        case ETHERTYPE_IP:
            ParseIPPacket(packet, timestamp, protocol);
            break;
        case ETHERTYPE_ARP:
            std::cout << "ARP" << std::endl;
            break;
        case ETHERTYPE_REVARP:
            std::cout << "RARP" << std::endl;
            break;
        default:
            std::cout << "Other" << std::endl;
    }
}

void PacketProcessor::ParseIPPacket(const std::vector<uint8_t> &packet, const std::string &timestamp, int protocol)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));


    IPHeader* iph = reinterpret_cast<IPHeader*>(const_cast<uint8_t*>(packet.data()) + ETHERNET_HEADER_SIZE);

    char srcIPBuffer[INET_ADDRSTRLEN];
    char dstIPBuffer[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(iph->saddr), srcIPBuffer, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &(iph->daddr), dstIPBuffer, INET_ADDRSTRLEN);

    srcIP = srcIPBuffer;
    dstIP = dstIPBuffer;

    size_t ipHeaderLength = iph->ihl * 4;

    // Check if the packet's protocol matches the specified protocol
    if (protocol == -1 || iph->protocol == protocol) // TODO: fix protocol check
    { 
        switch (protocol) {
            case IPPROTO_TCP:
                ParseTCPPacket(packet, ipHeaderLength, timestamp);
                break;
            case IPPROTO_UDP:
                ParseUDPPacket(packet, ipHeaderLength, timestamp);
                break;
            case IPPROTO_ICMP:
                ParseICMPPacket(packet, ipHeaderLength, timestamp);
                break;
            case IPPROTO_IGMP:
                ParseIGMPPacket(packet, ipHeaderLength, timestamp);
                break;
            default:
                PrintPacketInfo("", srcIP, dstIP, 0, 0, packet.size(), "Other");
                break;
        }
    }
}

void PacketProcessor::ParseTCPPacket(const std::vector<uint8_t> &packet, size_t ipHeaderLength, const std::string &timestamp)
{
    TCPHeader* tcph = reinterpret_cast<TCPHeader*>(const_cast<uint8_t*>(packet.data()) + ETHERNET_HEADER_SIZE + ipHeaderLength);

    uint16_t srcPort = ntohs(tcph->source);
    uint16_t dstPort = ntohs(tcph->dest);

    PrintPacketInfo(timestamp, srcIP, dstIP, srcPort, dstPort, packet.size(), "TCP");
}

void PacketProcessor::ParseUDPPacket(const std::vector<uint8_t> &packet, size_t ipHeaderLength, const std::string &timestamp)
{
    UDPHeader* udph = reinterpret_cast<UDPHeader*>(const_cast<uint8_t*>(packet.data()) + ETHERNET_HEADER_SIZE + ipHeaderLength);

    uint16_t srcPort = ntohs(udph->source);
    uint16_t dstPort = ntohs(udph->dest);

    PrintPacketInfo(timestamp, srcIP, dstIP, srcPort, dstPort, packet.size(), "UDP");
}

void PacketProcessor::ParseICMPPacket(const std::vector<uint8_t> &packet, size_t ipHeaderLength, const std::string &timestamp)
{
    ICMPHeader* icmph = reinterpret_cast<ICMPHeader*>(const_cast<uint8_t*>(packet.data()) + ETHERNET_HEADER_SIZE + ipHeaderLength);

    PrintPacketInfo(timestamp, srcIP, dstIP, 0, 0, packet.size(), "ICMP");
}

void PacketProcessor::ParseIGMPPacket(const std::vector<uint8_t> &packet, size_t ipHeaderLength, const std::string &timestamp)
{
    IGMPHeader* igmph = reinterpret_cast<IGMPHeader*>(const_cast<uint8_t*>(packet.data()) + ETHERNET_HEADER_SIZE + ipHeaderLength);

    PrintPacketInfo(timestamp, srcIP, dstIP, 0, 0, packet.size(), "IGMP");
}

void PacketProcessor::PrintPacketInfo(const std::string &timestamp, const std::string &srcIP, const std::string &dstIP, 
                                        uint16_t srcPort, uint16_t dstPort, size_t packetSize, const std::string &protocol)
{
    std::cout << "Timestamp: " << timestamp << ", Protocol: " << protocol
              << ", Source IP: " << srcIP << ", Dest IP: " << dstIP
              << ", Source Port: " << srcPort << ", Dest Port: " << dstPort
              << ", Payload: " << packetSize - ETHERNET_HEADER_SIZE << " bytes" << std::endl; // TODO: Fix payload size
}
