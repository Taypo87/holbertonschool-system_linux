#include "socket.h"

int main(int argc, char **argv)
{
	int socketfd;
	struct sockaddr_in *addr = calloc(1, sizeof(struct sockaddr_in));
	socklen_t addr_size = sizeof(struct sockaddr_in);
	char *local = "localhost";

	if (argc != 3)
	{
		printf("Usage: %s <host> <port>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	socketfd = socket(AF_INET, SOCK_STREAM, 0);
	addr->sin_family = AF_INET;
	addr->sin_port = htons(atoi(argv[2]));
	if (strcmp(local, argv[1]) == 0)
		inet_pton(AF_INET, "127.0.0.1", &addr->sin_addr);
	else
		inet_pton(AF_INET, argv[1], &(addr->sin_addr));
	if (connect(socketfd, (struct sockaddr *)addr, addr_size) == 0)
	{
		printf("Connected to %s:%s\n", argv[1], argv[2]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("ERROR\n");
		exit(EXIT_FAILURE);
	}

}