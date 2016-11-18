#if !defined( TCP_H )
#define TCP_H
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include "tcp.h"
#include "affichage.h"

void castPacketTcp(const u_char *packet,int profondeur,int verbose);

void printPacketTcp(const struct tcphdr *tcpHeader,int profondeur,int verbose);

#endif