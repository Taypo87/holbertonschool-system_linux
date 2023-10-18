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
int initiate_socket();
int accept_connection(int socketfd);
void request_received(int clientfd);



#endif