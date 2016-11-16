	#include <stdio.h>
	#include <net/ethernet.h>
	#include <pcap.h>
	
		void traitement_packet(u_char *args, const struct pcap_pkthdr *header,const u_char *packet);
/*
	struct pcap_pkthdr {
		struct timeval ts; // time stamp
		bpf_u_int32 caplen; // length of portion present 
		bpf_u_int32 len; // length this packet (off wire) 
	};
*/
		void traitement_packet(u_char *args, const struct pcap_pkthdr *header,const u_char *packet)
		{	
			printf("%d\n",header->len);
			cast_packet_ethernet(packet);
		}

	

	int main(int argc, char *argv[])
	{
		char *dev;
		char errbuf[PCAP_ERRBUF_SIZE];
		pcap_t *handle;
	 	bpf_u_int32 mask;		/* The netmask of our sniffing device */
	 	bpf_u_int32 net;		/* The IP of our sniffing device */
		struct pcap_pkthdr header;	/* The header that pcap gives us */
		const u_char *packet;		/* The actual packet */


/*
		dev = pcap_lookupdev(errbuf);
		if (dev == NULL) {
			fprintf(stderr, "Couldn't find default device: %s\n", errbuf);
			return(2);
		}
*/
	dev = "eth1";
	handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
	if (handle == NULL) {
		 fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
		 return(2);
	 }
	
	if (pcap_lookupnet(dev, &net, &mask, errbuf) == -1) {
		 fprintf(stderr, "Can't get netmask for device %s: %s\n", dev,errbuf);
		 net = 0;
		 mask = 0;
	 }
		printf("Device: %s\n", dev);
		pcap_loop(handle,0,traitement_packet,NULL);
		/* Print its length */
		return(0);
	}
