#ifndef PACKET_H
#define PACKET_H

#include <vector>
#include <stdint.h>

class Packet
{
public:
    explicit Packet(const std::vector<uint8_t>& data);

private:
    std::vector<uint8_t> m_data;
    
};

#endif // PACKET_H




