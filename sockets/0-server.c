#include "socket.h"
/**
 * main - sets up a listening socket
 * Return: 0 on success, a sginal should kill program before returning
*/
int main(void)
{
	int socketfd, backlog = 8;
	struct sockaddr_in *address;

	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	address = calloc(1, sizeof(struct sockaddr_in));
	address->sin_family = AF_INET;
	address->sin_port = htons(12345);
	address->sin_addr.s_addr = INADDR_ANY;
	bind(socketfd, (struct sockaddr *)address, sizeof(struct sockaddr_in));
	printf("Server listening on port 12345\n");
	while (listen(socketfd, backlog) == 0)
	{

	}
	return (0);
}
