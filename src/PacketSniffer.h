#ifndef PACKET_SNIFFER_H
#define PACKET_SNIFFER_H

#include"RawSocket.h"
#include"PacketProcessor.h"

class PacketSniffer {
public:
    PacketSniffer();

    void Start(int protocol = ETH_P_ALL);
    void Stop();
    bool IsRunning() const;

private:
   PacketProcessor m_processPacket;
   RawSocket m_socket;
   bool b_running;
};

#endif // PACKET_SNIFFER_H
