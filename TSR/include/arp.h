#if !defined( ARP_H )
#define ARP_H
#include <net/if_arp.h>
#include <arpa/inet.h>
#include "udp.h"
#include "tcp.h"
#include "affichage.h"

void castPacketArp(const u_char *packet,int profondeur,int verbose);

void printPacketArp(const struct arphdr *ipHeader,int profondeur,int verbose);

#endif