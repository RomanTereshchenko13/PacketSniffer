#ifndef PROCESSPACKET_H
#define PROCESSPACKET_H

#include <vector>

class ProcessPacket
{
public:
    ProcessPacket();
    void Process(const std::vector<uint8_t>& packet);

    unsigned long long GetTotalReceivedBytes() const;
    unsigned long long GetTotalSentBytes() const;

private:
    unsigned long long m_totalReceivedBytes;
    unsigned long long m_totalSentBytes;
};

#endif // PROCESSPACKET_H
