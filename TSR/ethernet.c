#include <net/ethernet.h>
#include <netinet/ether.h>
#include <netinet/in.h>
#include <stdio.h>
void cast_packet_ethernet(const u_char *packet)
{
	const struct ether_header *ethernet_header =(const struct  ether_header *) packet;
	printf("Cast packet\n");
	printf("Dest @ %s\n",ether_ntoa((const struct ether_addr *)&ethernet_header->ether_dhost));
	printf("Sour @ %s\n",ether_ntoa((const struct ether_addr *)&ethernet_header->ether_shost));
	size_t ethernet_header_size = sizeof(struct ether_header);
	printf("Taille Header %zu \n",ethernet_header_size);
	
	uint16_t ether_type = ntohs(ethernet_header->ether_type);//Convert to little indian (Touts les champs de taille > 1 octet)
	//Traitement de la valeur de type
	switch(ether_type){
		case ETHERTYPE_IP:
			printf("%d : IPV4\n",ether_type);
			//Traitement du packet
			//cast_packet_ipv4(packet+tailleheader)
			break;
		case ETHERTYPE_ARP:
			printf("%d : ARP\n",ether_type);
			//Traitement du packet
			break;
		case ETHERTYPE_IPV6:
			printf("%d : IPV6\n",ether_type);
		default:
			printf("%d : Type non reconnu\n",ether_type);
}
}

