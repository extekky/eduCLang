#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "leetcode.h"
#include "lib_of_books.h"
#include "makeMassive.h"
#include "mystring.h"
#include "udp_packet.h"

int main(void)  
{
        udpPacket packet;

        packet.s_port = htons(12345);
        packet.d_port = htons(54321);

        const char *message = "Hello, UDP!";

        strncpy(packet.data, message, MAX_DATA_SIZE - 1);

        packet.data[MAX_DATA_SIZE - 1] = '\0';
        packet.length =
            htons(sizeof(packet) - MAX_DATA_SIZE + strlen(packet.data) + 1);
        packet.checksum = 0;

        int sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
        if (sock < 0) {
                perror("Errro socket creation.");
                return 1;
        }

        struct sockaddr_in dest_addr;
        memset(&dest_addr, 0, sizeof(dest_addr));
        dest_addr.sin_family = AF_INET;
        dest_addr.sin_port = packet.d_port;
        inet_pton(AF_INET, "127.0.0.1", &dest_addr.sin_addr);

        ssize_t bytes_sent =
            sendto(sock, &packet, ntohs(packet.length), 0,
                   (struct sockaddr *)&dest_addr, sizeof(dest_addr));
        if (bytes_sent < 0) {
                perror("Error packet trasmit");
                close(sock);
                return 1;
        }

        printf("Send %zd byte\n", bytes_sent);

        close(sock);
        return 0;
}
