#ifndef PACKET_SNIFFER_H
#define PACKET_SNIFFER_H

#include"RawSocket.h"

class PacketSniffer {
public:
    PacketSniffer();
    ~PacketSniffer();

    void Start();
    void Stop();

private:
   RawSocket m_socket;
};

#endif // PACKET_SNIFFER_H
