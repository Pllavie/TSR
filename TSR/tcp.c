#include "include/tcp.h"

void castPacketTcp(const u_char *packet,int profondeur,int verbose)
{
	const struct tcphdr *tcpHeader = (const struct tcphdr *) packet;
	printPacketTcp(tcpHeader,profondeur+1,verbose);
}
/*
struct tcphdr
  {
    u_int16_t source;
    u_int16_t dest;
    u_int32_t seq;
    u_int32_t ack_seq;
#  if __BYTE_ORDER == __LITTLE_ENDIAN
    u_int16_t res1:4;
    u_int16_t doff:4;
    u_int16_t fin:1;
    u_int16_t syn:1;
    u_int16_t rst:1;
    u_int16_t psh:1;
    u_int16_t ack:1;
    u_int16_t urg:1;
    u_int16_t res2:2;
#  elif __BYTE_ORDER == __BIG_ENDIAN
    u_int16_t doff:4;
    u_int16_t res1:4;
    u_int16_t res2:2;
    u_int16_t urg:1;
    u_int16_t ack:1;
    u_int16_t psh:1;
    u_int16_t rst:1;
    u_int16_t syn:1;
    u_int16_t fin:1;
#  else
#   error "Adjust your <bits/endian.h> defines"
#  endif
    u_int16_t window;
    u_int16_t check;
    u_int16_t urg_ptr;
};
*/
void printPacketTcp(const struct tcphdr *tcpHeader,int profondeur,int verbose)
{
	printf("\033[%sm",TCP_BLEU);
    if(verbose==1)
    {
        printf("TCP");
        printf("\n");
    }
    else if(verbose==2)
    {
        printf("TCP ");
        printf("Flags: ");
        if(tcpHeader->syn!=0){printf("SYN ");}
        if(tcpHeader->rst!=0){printf("RST ");}
        if(tcpHeader->psh!=0){printf("PSH ");}
        if(tcpHeader->ack!=0){printf("ACK ");}
        if(tcpHeader->urg!=0){printf("URG ");}
        if(tcpHeader->fin!=0){printf("FIN ");}
    printf("\n");
    }
    else if(verbose==3)
    {
	tab(profondeur);printf("TCP\n");
	tab(profondeur);printf("Source : %u\n",tcpHeader->source);
	tab(profondeur);printf("Dest : %u\n",tcpHeader->dest);
	tab(profondeur);printf("Seq Number: %u\n",tcpHeader->seq);
	tab(profondeur);printf("Ack Number: %d\n",tcpHeader->ack_seq);
	tab(profondeur);printf("Data Offset : %d\n",tcpHeader->doff);
	tab(profondeur);printf("Flags: ");
		if(tcpHeader->syn!=0){printf("SYN ");}
		if(tcpHeader->rst!=0){printf("RST ");}
		if(tcpHeader->psh!=0){printf("PSH ");}
		if(tcpHeader->ack!=0){printf("ACK ");}
		if(tcpHeader->urg!=0){printf("URG ");}
		if(tcpHeader->fin!=0){printf("FIN ");}
	printf("\n");
	tab(profondeur);printf("Window %d\n",tcpHeader->window);
	tab(profondeur);printf("Check Sum %d\n",tcpHeader->check);
	tab(profondeur);printf("Urgent Pointer %d\n",tcpHeader->urg_ptr);
    }
	printf("\033[%sm","0");
}