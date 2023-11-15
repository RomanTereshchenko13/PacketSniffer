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
    void Process(const std::vector<uint8_t>& packet);

    unsigned long long GetTotalReceivedBytes() const;
    unsigned long long GetTotalSentBytes() const;

private:
    unsigned long long m_totalReceivedBytes;
    unsigned long long m_totalSentBytes;
};

#endif // PACKETPROCESSOR_H
