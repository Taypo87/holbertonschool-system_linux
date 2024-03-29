#ifndef _SOCKET_
#define _SOCKET_


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

typedef struct todos {
    struct todos *next;
    struct todos *prev;
    char *title;
    char *description;
    int id;
} todos;

typedef struct client_info {
    int clientfd;
    char *clientip;
} client_info;

typedef struct todo_list {
    struct todos **head;
    struct todos **tail;
    int size;
} todo_list;


void requst_breakdown_printout(void *message_received);
int initiate_socket();
int accept_connection(int socketfd);
char * request_received(int clientfd);
void task5_breakdown(void *message_received);
void task6_breakdown(char *message_received);
int header_kv(char *start, char *end);
void task7_breakdown(char * message_received);
void task8_breakdown(char *msgrcv);
struct client_info *accept_connection_api(int socketfd);
char *request_received_api(client_info *client);
int parse_request(char *msgrcv, client_info *client);
todo_list *post_method(char *start);
void get_method(todo_list *list, client_info *client);
char *construct_json(todos *node);
void empty_list(client_info *client);



#endif