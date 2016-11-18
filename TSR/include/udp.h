#if !defined( UDP_H )
#define UDP_H
#include <netinet/udp.h>
#include <arpa/inet.h>
#include "affichage.h"
#define UDP_JAUNE "33"

void castPacketUdp(const u_char *packet,int profondeur,int verbose);

void printPacketUdp(const struct udphdr *udpHeader,int profondeur,int verbose);

#endif