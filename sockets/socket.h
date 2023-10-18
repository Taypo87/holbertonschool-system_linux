#ifndef _SOCKET_
#define _SOCKET_


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>


void requst_breakdown_printout(void *message_received);
int initiate_socket(struct sockaddr_in *address);
int accept_connection(struct sockaddr *inbound_address, int socketfd);
void request_received(int clientfd);



#endif