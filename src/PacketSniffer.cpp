#include "PacketSniffer.h"

PacketSniffer::PacketSniffer() 
    : b_running(true), m_processPacket() {}

PacketSniffer::~PacketSniffer()
{

}

void PacketSniffer::Start(int protocol)
{
    b_running = true;
    while (b_running) {
        RawSocket socket(protocol);
        std::vector<uint8_t> packet = socket.ReceivePacket();
        m_processPacket.ProcessPacket(packet);
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
