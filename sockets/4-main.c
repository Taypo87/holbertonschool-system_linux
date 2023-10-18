#include "socket.h"
/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, clientfd, backlog = 8;

	socketfd = initiate_socket();
	printf("Server listening on port 8080\n");
	while (listen(socketfd, backlog) == 0)
	{
		
		clientfd = accept_connection(socketfd);
		request_received(clientfd);
	}
    fflush(stdout);
	return (0);
}