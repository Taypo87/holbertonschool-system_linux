#include "socket.h"
/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, clientfd, backlog = 8;
    char * msgrcv;

	socketfd = initiate_socket();
	printf("Server listening on port 8080\n");
	while (listen(socketfd, backlog) == 0)
	{
		
		clientfd = accept_connection(socketfd);
		msgrcv = request_received(clientfd);
        task7_breakdown(msgrcv);
	}
	return (0);
}