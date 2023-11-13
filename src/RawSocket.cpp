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
    const size_t bufferSize = 65536;
    std::vector<uint8_t> buffer(bufferSize);

    sockaddr_in sender;
    socklen_t senderSize = sizeof(sender);

    ssize_t packetSize = recvfrom(m_sockfd, buffer.data(), bufferSize, 0, 
                                  reinterpret_cast<sockaddr*>(&sender), &senderSize);

    if (packetSize < 0)
    {
        perror("recvfrom() failed");
        exit(EXIT_FAILURE);
    }

    buffer.resize(packetSize);
    return buffer;
}

int RawSocket::GetDescriptor() const
{
    return m_sockfd;
}
