#ifndef PACKET_SNIFFER_H
#define PACKET_SNIFFER_H

class PacketSniffer {
public:
    PacketSniffer();
    ~PacketSniffer();

    void Start();
    void Stop();
};

#endif // PACKET_SNIFFER_H

