#ifndef RAWSOCKET_H
#define RAWSOCKET_H

#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/ethernet.h> 
#include <linux/if_packet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class RawSocket
{
public:
    RawSocket(int protocol = ETH_P_ALL, size_t bufferSize = 65536);
    ~RawSocket();

    RawSocket(const RawSocket&) = delete;
    RawSocket& operator=(const RawSocket&) = delete;

    RawSocket(RawSocket&&) = default;
    RawSocket& operator=(RawSocket&&) = default;

    std::vector<uint8_t> ReceivePacket();
    int GetDescriptor() const;

private:
    int m_sockfd;
    size_t m_bufferSize;
};


#endif // RAWSOCKET_H
