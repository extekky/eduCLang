#ifndef UDP_PACKET_H

#include <arpa/inet.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_DATA_SIZE 512

typedef struct udp_packet {
        uint16_t s_port;
        uint16_t d_port;
        uint16_t length;
        uint16_t checksum;
        char data[MAX_DATA_SIZE];
} udpPacket;

#endif