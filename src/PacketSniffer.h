#ifndef PACKET_SNIFFER_H
#define PACKET_SNIFFER_H

#include<iostream>

#include"RawSocket.h"
#include"PacketProcessor.h"

class PacketSniffer {
public:
    PacketSniffer();
    ~PacketSniffer();

    void Start(int protocol = ETH_P_ALL);
    void Stop();
    bool IsRunning() const;

private:
   RawSocket m_socket;
   PacketProcessor m_processPacket;
   bool b_running;
};

#endif // PACKET_SNIFFER_H
