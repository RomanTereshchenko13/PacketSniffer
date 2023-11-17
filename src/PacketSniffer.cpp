#include "PacketSniffer.h"

PacketSniffer::PacketSniffer() 
    : b_running(true), m_processPacket(), m_socket() {}

void PacketSniffer::Start(int protocol)
{
    b_running = true;

    while (b_running) {
        std::vector<uint8_t> packet = m_socket.ReceivePacket();
        m_processPacket.ProcessPacket(packet, protocol);
    }
}

void PacketSniffer::Stop()
{
    b_running = false;
}

bool PacketSniffer::IsRunning() const
{
    return b_running;
}
