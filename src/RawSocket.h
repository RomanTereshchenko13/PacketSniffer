#ifndef RAWSOCKET_H
#define RAWSOCKET_H

#include <vector>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

class RawSocket
{
public:
    RawSocket();
    ~RawSocket();

    std::vector<uint8_t> ReceivePacket();
    int GetDescriptor() const;

private:
    int m_sockfd;    
};


#endif // RAWSOCKET_H
