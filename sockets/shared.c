#include "socket.h"

void requst_breakdown_printout(void *message_received)
{
    char *token;
    token = (char *)message_received;
    token = strtok(token, " ");
    printf("Method: %s\n", token);
    token = strtok(NULL, " ");
    printf("Path: %s\n", token);
    token = strtok(NULL, " ");
    printf("Version: %s\n", token);
}

int initiate_socket()
{
    int socketfd;
    struct sockaddr_in *address;

    socketfd = socket(AF_INET, SOCK_STREAM, 0);
	address = calloc(1, sizeof(struct sockaddr_in));
	address->sin_family = AF_INET;
	address->sin_port = htons(8080);
	address->sin_addr.s_addr = INADDR_ANY;
	bind(socketfd, (struct sockaddr *)address, sizeof(struct sockaddr_in));

    return (socketfd);
}

int accept_connection(int socketfd)
{
    socklen_t *inbound_addrlength = calloc(1, sizeof(socklen_t));
    struct sockaddr *inbound_address = calloc(1, sizeof(struct sockaddr));
    struct sockaddr_in *inbound_address_in;
    int clientfd;

    *inbound_addrlength = (socklen_t)sizeof(struct sockaddr);
    clientfd = accept(socketfd, inbound_address, inbound_addrlength);
    inbound_address_in = (struct sockaddr_in *)inbound_address;
    printf("Client connected: %s\n", inet_ntoa(inbound_address_in->sin_addr));

    return (clientfd);
}
void request_received(int clientfd)
{
    char message_received[4096], message_sent[4096];
    ssize_t byte_received;
    size_t message_size = sizeof(message_sent);

    byte_received = recv(clientfd, message_received, sizeof(message_received), 0);
	if (byte_received > 0)
	{
		message_received[byte_received] = '\0';
		printf("Raw request: \"%s\"\n", message_received);
        snprintf(message_sent, sizeof(message_sent),
             "HTTP/1.1 200 OK\r\n");
        send(clientfd, message_sent, message_size, 0);
        requst_breakdown_printout((void *)message_received);
        close(clientfd);
    }
}