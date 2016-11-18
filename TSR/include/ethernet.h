#if !defined( ETHERNET_H )
#define ETHERNET_H
#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include "affichage.h"
#include "ip.h"
#include <stdio.h>
#define ETHERNET_LEN 14

void castPacketEthernet(const u_char *packet,int profondeur,int verbose);//Affiche le contenu du packet ethernet et retourne le ether_type

void printPacketEthernet(const struct ether_header *ether_header,int profondeur,int verbose);

#endif