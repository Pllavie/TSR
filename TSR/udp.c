#include "include/udp.h"

void castPacketUdp(const u_char *packet,int profondeur,int verbose)
{
	const struct udphdr *udpHeader = (const struct udphdr *) packet;
	printPacketUdp(udpHeader,profondeur+1,verbose);
}

void printPacketUdp(const struct udphdr *udpHeader,int profondeur,int verbose)
{
	printf("\033[%sm",UDP_JAUNE);
	if(verbose==1)
	{
		printf("UDP");
		printf("\n");
	}
	else if(verbose==2)
	{
		printf("UDP ");
		printf("Source Port : %u ",ntohs(udpHeader->source));
		printf("Dest Port : %u ",udpHeader->dest);
		printf("\n");
	}
	else if(verbose==3)
	{
	tab(profondeur);printf("UDP\n");
	tab(profondeur);printf("Source Port : %u\n",ntohs(udpHeader->source));
	tab(profondeur);printf("Dest Port : %u\n",ntohs(udpHeader->dest));
	tab(profondeur);printf("Length : %u\n",ntohs(udpHeader->len));
	tab(profondeur);printf("Check Sum : %d\n",ntohs(udpHeader->check));
	}
	printf("\033[%sm","0");
}