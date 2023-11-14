#include "ProcessPacket.h"

ProcessPacket::ProcessPacket() 
    : m_totalReceivedBytes(0), m_totalSentBytes(0) {}

void ProcessPacket::Process(const std::vector<uint8_t>&packet)
{
        if (packet.size() < sizeof(struct ip)) {
            return; // Packet is too small to be valid
        }

        m_totalReceivedBytes += packet.size();
}

unsigned long long ProcessPacket::GetTotalReceivedBytes() const
{
    return m_totalReceivedBytes;
}

unsigned long long ProcessPacket::GetTotalSentBytes() const
{
    return m_totalSentBytes;
}
