#include "RawSocket.h"

RawSocket::RawSocket(int protocol, size_t bufferSize) : m_buffer(bufferSize)
{
    m_sockfd = socket(AF_PACKET, SOCK_RAW, htons(protocol));
    if(m_sockfd < 0)
    {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
}

RawSocket::~RawSocket()
{
    if(close(m_sockfd) < 0)
    {
        perror("close() failed");
        exit(EXIT_FAILURE);
    }
}

std::vector<uint8_t> RawSocket::ReceivePacket()
{
    sockaddr_ll sender;
    socklen_t senderSize = sizeof(sender);

    ssize_t packetSize = recvfrom(m_sockfd, m_buffer.data(), m_buffer.size(), 0, 
                                  reinterpret_cast<sockaddr*>(&sender), &senderSize);

    if (packetSize < 0)
    {
        perror("recvfrom() failed");
        exit(EXIT_FAILURE);
    }

    m_buffer.resize(packetSize);
    return m_buffer;
}

int RawSocket::GetDescriptor() const
{
    return m_sockfd;
}
