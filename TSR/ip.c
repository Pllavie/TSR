#include "include/ip.h"


void castPacketIp(const u_char *packet,int profondeur,int verbose)
{
	const struct ip *ipHeader = (const struct ip *) packet;
	printPacketIp(ipHeader,profondeur+1,verbose);

	switch(ipHeader->ip_p){
		case 0x11://UDP
			castPacketUdp((packet+(ipHeader->ip_hl*4)),profondeur+1,verbose);
			break;
		case 0x06://TCP
			castPacketTcp((packet+(ipHeader->ip_hl*4)),profondeur+1,verbose);
			break;
		default:
			printf("%u : Type non reconnu\n",ipHeader->ip_p);
					}
}

void printPacketIp(const struct ip *ipHeader,int profondeur,int verbose)
{
	printf("\033[%sm",IP_VERT);
	if(verbose==1)
	{
		printf("IP");
	}
	if(verbose==2)
	{
		printf("IP ");
		printf("Version : %u ",ipHeader->ip_v);
		if(ipHeader->ip_p==0x11)//UDP
		{
		printf("Protocol : UDP ");
		}
		if(ipHeader->ip_p==0x06)//TCP
		{
			printf("Protocol : TCP ");
		}
		printf("\n");
	}
	if(verbose==3)
	{
	tab(profondeur);printf("IP\n");
	tab(profondeur);printf("Version : %u\n",ipHeader->ip_v);
	tab(profondeur);printf("Header Length : %u\n",ipHeader->ip_hl);
	tab(profondeur);printf("Type of Service : %u\n",ipHeader->ip_tos);
	tab(profondeur);printf("Total Length : %d\n",ipHeader->ip_len);
	tab(profondeur);printf("Identification : %d\n",ipHeader->ip_id);
	tab(profondeur);printf("Fragment Offset Field %d\n",ipHeader->ip_off);
	tab(profondeur);printf("Time To Live %d\n",ipHeader->ip_ttl);
	if(ipHeader->ip_p==0x11)//UDP
	{
		tab(profondeur);printf("Protocol : UDP\n");
	}
	if(ipHeader->ip_p==0x06)//TCP
	{
		tab(profondeur);printf("Protocol : TCP\n");
	}
	tab(profondeur);printf("Check Sum %d\n",ipHeader->ip_sum);
	tab(profondeur);printf("Source Adress %s\n",inet_ntoa(*(struct in_addr*)&ipHeader->ip_src));
	tab(profondeur);printf("Dest Adress %s\n",inet_ntoa(*(struct in_addr*)&ipHeader->ip_dst));
	}
	printf("\033[%sm","0");
}