#include "socket.h"
/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, backlog = 8;
    char *msgrcv;
    client_info *client;

	socketfd = initiate_socket();
	printf("Server listening on port 8080\n");
	while (listen(socketfd, backlog) == 0)
	{
		
		client = accept_connection_api(socketfd);
		msgrcv = request_received_api(client);
        parse_request(msgrcv, client);
	}
	return (0);
}
