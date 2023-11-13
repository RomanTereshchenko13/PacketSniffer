#include "RawSocket.h"

RawSocket::RawSocket()
{
    m_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_IP);
    if(m_sockfd < 0)
    {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
}

RawSocket::~RawSocket()
{
    close(m_sockfd);
}

std::vector<uint8_t> RawSocket::ReceivePacket()
{
    return std::vector<uint8_t>();
}

int RawSocket::GetDescriptor() const
{
    return m_sockfd;
}
