#include "socket.h"
/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, clientfd, backlog = 8;
	struct sockaddr_in *address = NULL;
	struct sockaddr *inbound_address = NULL;

	socketfd = initiate_socket(address);
	printf("Server listening on port 8080\n");
	while (listen(socketfd, backlog) == 0)
	{
		
		clientfd = accept_connection(inbound_address, socketfd);
		request_received(clientfd);
	}
	return (0);
}