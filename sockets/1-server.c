#include "socket.h"
/**
 * main - sets up a listening socket and accepts connections
 * Return: 0 on success
*/
int main(void)
{
	int socketfd, backlog = 8;
	struct sockaddr_in *address, *inbound_in;
	struct sockaddr *inbound_address;
	socklen_t *inbound_addrlength;
	char *ip;
	
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	address = calloc(1, sizeof(struct sockaddr_in));
	inbound_address = calloc(1, sizeof(struct sockaddr));
	address->sin_family = AF_INET;
	address->sin_port = htons(12345);
	address->sin_addr.s_addr = INADDR_ANY;
	bind(socketfd, (struct sockaddr *)address, sizeof(struct sockaddr_in));
	printf("Server listening on port 12345\n");
	while (listen(socketfd, backlog) == 0)
	{
		accept(socketfd, inbound_address, inbound_addrlength);
		inbound_in = (struct sockaddr_in *)inbound_address;
		ip = inet_ntoa(inbound_in->sin_addr);
		printf("Client connected: %s", ip);
		printf("\n");
		break;
	}
	return (0);
}