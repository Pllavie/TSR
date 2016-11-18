#include "include/arp.h"

void castPacketArp(const u_char *packet,int profondeur,int verbose)
{
	const struct arphdr *arpHeader = (const struct arphdr *) packet;
	printPacketArp(arpHeader,profondeur+1,verbose);
}

void printPacketArp(const struct arphdr *arpHeader,int profondeur,int verbose){
	printf("\033[%sm",ARP_MAGENTA);
	if(verbose==1)
	{
		printf("ARP");
		printf("\n");
	}
	if(verbose==2)
	{
		printf("ARP ");
		printf("Command : ");
		switch(ntohs(arpHeader->ar_op))
		{
			case(ARPOP_REQUEST):printf("ARP REQUEST ");break;
			case(ARPOP_REPLY):printf("ARP REPLY ");break;
			case(ARPOP_RREQUEST):printf("RARP REQUEST ");break;
			case(ARPOP_RREPLY):printf("RARP REPLY ");break;
			case(ARPOP_InREQUEST):printf("INARP REQUEST ");break;
			case(ARPOP_InREPLY):printf("INARP REPLY ");break;
			case(ARPOP_NAK):printf("ATMARP NACK ");break;
		}
		printf("\n");

	}
	if(verbose==3)
	{
	tab(profondeur);printf("ARP\n");
	tab(profondeur);printf("Format HardWare @ : %u\n",arpHeader->ar_hrd);
	tab(profondeur);printf("Format Protocol @ : %u\n",arpHeader->ar_pro);
	tab(profondeur);printf("Length HardWare @ : %u\n",arpHeader->ar_hln);
	tab(profondeur);printf("Length Protocol @: %d\n",arpHeader->ar_pln);
		tab(profondeur);printf("Command : ");
		switch(ntohs(arpHeader->ar_op))
		{
			case(ARPOP_REQUEST):printf("ARP REQUEST ");break;
			case(ARPOP_REPLY):printf("ARP REPLY ");break;
			case(ARPOP_RREQUEST):printf("RARP REQUEST ");break;
			case(ARPOP_RREPLY):printf("RARP REPLY ");break;
			case(ARPOP_InREQUEST):printf("INARP REQUEST ");break;
			case(ARPOP_InREPLY):printf("INARP REPLY ");break;
			case(ARPOP_NAK):printf("ATMARP NACK ");break;
		}
		printf("\n");
	}
	printf("\033[%sm","0");
}