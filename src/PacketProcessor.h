#ifndef PACKETPROCESSOR_H
#define PACKETPROCESSOR_H

#include <vector>
#include <stdint.h>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <thread>

#include <netinet/tcp.h>  // struct tcphdr
#include <netinet/udp.h>  // struct udphdr
#include <netinet/ip_icmp.h> // struct icmphdr
#include <arpa/inet.h>
#include <net/ethernet.h> 

#include "Headers.h"

class PacketProcessor
{
public:
    PacketProcessor();
    void ProcessPacket(const std::vector<uint8_t>&packet, int protocol = IPPROTO_IP);

private:
    std::string srcIP;
    std::string dstIP;
    void ParseEthernetHeader(const std::vector<uint8_t>& packet, const std::string& timestamp, int protocol);
    void ParseIPPacket(const std::vector<uint8_t>& packet, const std::string& timestamp, int protocol);
    void ParseTCPPacket(const std::vector<uint8_t>& packet, size_t ipHeaderLength,  const std::string& timestamp);
    void ParseUDPPacket(const std::vector<uint8_t>& packet, size_t ipHeaderLength,  const std::string& timestamp);
    void ParseICMPPacket(const std::vector<uint8_t>& packet, size_t ipHeaderLength,  const std::string& timestamp);
    void ParseIGMPPacket(const std::vector<uint8_t>& packet, size_t ipHeaderLength,  const std::string& timestamp);
    void PrintPacketInfo(const std::string& timestamp, const std::string& srcIP, const std::string& dstIP, 
                         uint16_t srcPort, uint16_t dstPort, size_t packetSize, const std::string& protocol);

};

#endif // PACKETPROCESSOR_H
