#include "include/ethernet.h"

void castPacketEthernet(const u_char *packet,int profondeur,int verbose)
{
	const struct ether_header *ethernetHeader =(const struct  ether_header *) packet;
	printPacketEthernet(ethernetHeader,profondeur,verbose);
	
	uint16_t etherType = ntohs(ethernetHeader->ether_type);//Convert to little indian (Touts les champs de taille > 1 octet)
	switch(etherType){
		case ETHERTYPE_IP:
			castPacketIp(packet+ETHERNET_LEN,profondeur+1,verbose);
			break;
		case ETHERTYPE_ARP:
			castPacketArp(packet+ETHERNET_LEN,profondeur+1,verbose);
			break;
		case ETHERTYPE_IPV6:
			break;
		default:
			tab(profondeur);printf(": Type non reconnu\n",etherType);
					}
}

void printPacketEthernet(const struct ether_header *ethernetHeader,int profondeur,int verbose)
{
	uint16_t etherType = ntohs(ethernetHeader->ether_type);

	printf("\033[%sm",ETHERNET_ROUGE);
	if(verbose==1)
	{
		printf("ETHERNET");
	}
	else if(verbose==2)
	{
	printf("ETHERNET : Taille Header %d ",ETHERNET_LEN);
	printf("Dest @ %s ",ether_ntoa((const struct ether_addr *)&ethernetHeader->ether_dhost));
	printf("Sour @ %s ",ether_ntoa((const struct ether_addr *)&ethernetHeader->ether_shost));
	printf("\n");
	}
	else if (verbose==3)
	{
	tab(profondeur);printf("ETHERNET : Taille Header %d \n",ETHERNET_LEN);
	tab(profondeur);printf("Dest @ %s\n",ether_ntoa((const struct ether_addr *)&ethernetHeader->ether_dhost));
	tab(profondeur);printf("Sour @ %s\n",ether_ntoa((const struct ether_addr *)&ethernetHeader->ether_shost));
	}
	printf("\033[%sm","0");
}
