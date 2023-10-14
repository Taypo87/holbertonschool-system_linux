#include "socket.h"

int main(int argc, char **argv)
{
	int socketfd;
	struct sockaddr_in *addr;
	socklen_t addr_size = 1;

	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	addr->sin_port = htons(atoi(argv[2]));
	inet_pton(AF_INET, argv[1], &(addr->sin_addr));
	if (connect(socketfd, addr, addr_size) == 0)
	{
		printf("Connected to %s:%s", argv[1], argv[2]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		exit(EXIT_FAILURE);
	}

}