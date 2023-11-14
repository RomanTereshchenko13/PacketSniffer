#include "PacketSniffer.h"

PacketSniffer::PacketSniffer() 
    : b_running(true), m_socket(), m_processPacket() {}

PacketSniffer::~PacketSniffer()
{

}

void PacketSniffer::Start()
{
    b_running = true;
    while(b_running)
    {
        auto packet = m_socket.ReceivePacket();
        if(packet.size() > 0)
            m_processPacket.Process(packet);        
    }
}

void PacketSniffer::Stop()
{
    b_running = false;
}

std::pair<unsigned long long, unsigned long long> PacketSniffer::GetTotalBytes() const
{
    return std::make_pair(m_processPacket.GetTotalReceivedBytes(), m_processPacket.GetTotalSentBytes());
}

bool PacketSniffer::IsRunning() const
{
    return b_running;
}
