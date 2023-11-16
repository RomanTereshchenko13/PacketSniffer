#ifndef PACKETPROCESSOR_H
#define PACKETPROCESSOR_H

#include <vector>
#include <stdint.h>

#include <netinet/ip.h>   // struct ip
#include <netinet/tcp.h>  // struct tcphdr
#include <netinet/udp.h>  // struct udphdr
#include <netinet/ip_icmp.h> // struct icmphdr
#include <arpa/inet.h>
#include <net/ethernet.h> 

class PacketProcessor
{
public:
    PacketProcessor();
    void ProcessPacket(const std::vector<uint8_t>&packet);

private:

};

#endif // PACKETPROCESSOR_H
