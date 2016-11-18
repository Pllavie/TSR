#if !defined( IP_H )
#define IP_H
#include <netinet/ip.h>
#include <arpa/inet.h>
#include "udp.h"
#include "tcp.h"
#include "affichage.h"

void castPacketIp(const u_char *packet,int profondeur,int verbose);

void printPacketIp(const struct ip *ipHeader,int profondeur,int verbose);

#endif