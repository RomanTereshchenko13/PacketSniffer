#ifndef PACKET_SNIFFER_H
#define PACKET_SNIFFER_H

#include<iostream>

#include"RawSocket.h"
#include"ProcessPacket.h"

class PacketSniffer {
public:
    PacketSniffer();
    ~PacketSniffer();

    void Start();
    void Stop();

    std::pair<unsigned long long, unsigned long long> GetTotalBytes() const;
    bool IsRunning() const;

private:
   RawSocket m_socket;
   ProcessPacket m_processPacket;
   bool b_running;
};

#endif // PACKET_SNIFFER_H
