#ifndef HEADERS_H
#define HEADERS_H

#include <netinet/ip.h> 

const size_t ETHERNET_HEADER_SIZE = 14;

struct EthernetHeader {
    unsigned char dst_mac[6];
    unsigned char src_mac[6];
    unsigned short type;
};

struct IPHeader {
    unsigned char ihl:4;
    unsigned char version:4;
    unsigned char tos;
    unsigned short tot_len;
    unsigned short id;
    unsigned short frag_off;
    unsigned char ttl;
    unsigned char protocol;
    unsigned short check;
    unsigned int saddr;
    unsigned int daddr;
};

struct TCPHeader {
    u_short source;
    u_short dest;
    u_short seq;
    u_short ack_seq;
    u_short doff:4;
    u_short res1:4;
    u_short cwr:1;
    u_short ece:1;
    u_short urg:1;
    u_short ack:1;
    u_short psh:1;
    u_short rst:1;
    u_short syn:1;
    u_short fin:1;
    u_short window;
    u_short check;
    u_short urg_ptr;
};

struct UDPHeader {
    u_short source;
    u_short dest;
    u_short len;
    u_short check;
};

struct ICMPHeader {
    u_char type;
    u_char code;
    u_short checksum;
    u_short id;
    u_short seq;
};

struct IGMPHeader {
    u_char type;
    u_char code;
    u_short checksum;
    u_int groupAddress;
};

#endif // HEADERS_H



