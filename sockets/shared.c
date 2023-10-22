#include "socket.h"


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
    fflush(stdout);

    return (clientfd);
}

char * request_received(int clientfd)
{
    char message_received[4096], message_sent[4096], *msgrcv;
    ssize_t byte_received;
    size_t message_size = sizeof(message_sent);

    byte_received = recv(clientfd, message_received, sizeof(message_received), 0);
	if (byte_received > 0)
	{
		msgrcv = message_received;
		printf("Raw request: \"%s\"\n", message_received);
        snprintf(message_sent, sizeof(message_sent),
             "HTTP/1.1 200 OK\r\n");
        send(clientfd, message_sent, message_size, 0);
        close(clientfd);
        fflush(stdout);
    }
    return (msgrcv);
}

struct client_info *accept_connection_api(int socketfd)
{
    socklen_t *inbound_addrlength = calloc(1, sizeof(socklen_t));
    struct sockaddr *inbound_address = calloc(1, sizeof(struct sockaddr));
    struct sockaddr_in *inbound_address_in;
    struct client_info *client = calloc (1, sizeof(struct client_info)); 
    int clientfd;

    *inbound_addrlength = (socklen_t)sizeof(struct sockaddr);
    clientfd = accept(socketfd, inbound_address, inbound_addrlength);
    inbound_address_in = (struct sockaddr_in *)inbound_address;
    client->clientfd = clientfd;
    client->clientip = inet_ntoa(inbound_address_in->sin_addr);
    fflush(stdout);

    return (client);
}


char *request_received_api(client_info *client)
{
    //use this function to parse and check the request
    char message_received[4096], message_sent[4096], *msgrcv;
    ssize_t byte_received;
    size_t message_size = sizeof(message_sent);
    int error;

    byte_received = recv(client->clientfd, message_received, sizeof(message_received), 0);
	if (byte_received < 1)
        return(NULL);
	msgrcv = message_received;
    if (parse_request(msgrcv, client) < 0)
    {
        snprintf(message_sent, sizeof(message_sent),
             "404 Not Found\r\n");
        send(client->clientfd, message_sent, message_size, 0);
    }
    return (msgrcv);
}


int parse_request(char *msgrcv, client_info *client)
{
    char *start, *method, *path, message_sent[1024];
    size_t msglen, sent_len;
    todos **head;

    printf("%s\n", msgrcv);
    start = strdup(msgrcv);
    method = strtok(msgrcv, " ");
    path = strtok(NULL, " ");
    start = strstr(start, "\r\n\r\n") + 4;
    msglen = strlen(start);
    if (strcmp(path, "/todos") != 0)
        return (-1);
    if (strcmp(method, "POST") == 0)
    {
        head = post_method(start);
        if(!head)
        {
            snprintf(message_sent, sizeof(message_sent),
             "422 Unprocessable Entity\r\n");
            send(client->clientfd, message_sent, sizeof(message_sent), 0);
        }   
    }
    else if (strcmp(method, "GET") == 0)
        get_method(head, client);
    else
        return (-1);
    
}

todos **post_method(char *start)
{
    char *token;
    static todos **head;
    todos *temp, *new;

    new = calloc(1, sizeof(client_info));
    token = strtok(start, "=");
    if (token == NULL)
        return (NULL);
    token = strtok(NULL, "&");
    if (token == NULL)
        return (NULL);
    new->title = strdup(token);
    token = strtok(NULL, "=");
    if (token == NULL)
        return (NULL);
    token = strtok(NULL, "\r\n");
    if (token == NULL)
        return (NULL);
    new->description = strdup(token);
    new->next = NULL;
    if (!head)
        *head = new;
    else
    {
        temp = &head;
        new->next = temp;
        *head = new;
    }
    return(head);
}   

void get_method(char *start, client_info *client)
{
    char message_sent[1024];
    size_t message_size = sizeof(message_sent);
    snprintf(message_sent, sizeof(message_sent),
            "404 Not Found\r\n");
    send(client->clientfd, message_sent, message_size, 0);

}