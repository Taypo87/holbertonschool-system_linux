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
/*
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
    char message_received[8162], message_sent[8162], *msgrcv;
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
*/
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
    char message_sent[2048], *message_received;
    ssize_t byte_received;

    message_received = calloc(2048, sizeof(char));
    byte_received = recv(client->clientfd, message_received, 2048, 0);
	if (byte_received < 1)
        return(NULL);
    message_received[byte_received] = '\0';
    //printf("%s bytes:%ld\n", message_received, byte_received);
    if (parse_request(message_received, client) < 0)
    {
        snprintf(message_sent, 26,
             "HTTP/1.1 404 Not Found\r\n\n");
        send(client->clientfd, message_sent, 26, 0);
        close(client->clientfd);
        return (NULL);
    }
    return (message_received);
}


int parse_request(char *msgrcv, client_info *client)
{
    char *start, *method, *path, *body, message_sent[2048], *msg_copy;
    int msglen;
    todos **head = NULL;

    //printf("%s\n", msgrcv);
    if (!msgrcv)
        return(0);
    msg_copy = strdup(msgrcv);
    method = strtok(msg_copy, " ");
    path = strtok(NULL, " ");
    start = strstr(msgrcv, "\r\n\r\n") + 4;
    //printf("%s\n", start);
    if (strcmp(path, "/todos") != 0)
        return (-1);
    if (strcmp(method, "POST") == 0)
    {
        head = post_method(start);
        if(!head)
        {
            snprintf(message_sent, 37,
            "HTTP/1.1 422 Unprocessable Entity\r\n\n");
            send(client->clientfd, message_sent, 37, 0);
            close(client->clientfd);
            return (0);
        }
        else
        {
            body = construct_json(head);
            msglen = strlen(body);
            snprintf(message_sent, 2048,
            "HTTP/1.1 201 Created\r\nContent-Length: %d\r\nContent-Type: application/json\r\n\r\n%s",
              msglen, body);
            printf("%s\n", message_sent);
            send(client->clientfd, message_sent, 8162, 0);
        }  
    }
    else if (strcmp(method, "GET") == 0)
        get_method(head, client);
    else
        return (-1);
    return(0);
}

todos **post_method(char *start)
{
    char *token, *key1, *value1, *key2, *value2;
    todos **head;
    todos *temp, *new;
    static int id = 0;

    head = calloc(1, sizeof(todos));
    new = calloc(1, sizeof(todos));
    token = strtok(start, "=");
    key1 = strdup(token);
    if (token == NULL)
        return (NULL);
    token = strtok(NULL, "&");
    if (token == NULL)
        return (NULL); 
    value1 = strdup(token);
    token = strtok(NULL, "=");
    if (token == NULL)
        return (NULL);
    key2 = strdup(token);
    token = strtok(NULL, " \r\n");
    if (token == NULL)
        return (NULL);
    value2 = strdup(token);
    if (strcmp(key1, "title") == 0)
    {
        new->title = value1;
        new->description = value2;
    }
    else if (strcmp(key2, "title") == 0)
    {
        new->title = value2;
        new->description = value1;
    }
    else
        return (NULL);

    new->next = NULL;;
    new->id = id;
    if (!head)
        *head = new;
    else
    {
        temp = *head;
        new->next = temp;
        *head = new;
    }
    id++;
    return(head);
}   

void get_method(todos **head, client_info *client)
{
    char message_sent[1024];
    snprintf(message_sent, 27,
            "HTTP/1.1 404 Not Found\r\n\r\n");
    send(client->clientfd, message_sent, 27, 0);
    if(!head)
        return;

}
char *construct_json(todos **head)
{
    todos *temp;
    char jsonstr[1024], *strp;

    temp = *head;
    snprintf(jsonstr, 1024,
         "{\"id\":%d,\"title\":\"%s\",\"description\":\"%s\"}",
         temp->id, temp->title, temp->description);
    strp = jsonstr;
    //printf("%s\n", jsonstr);
    return(strp);

}