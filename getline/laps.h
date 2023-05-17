#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int car;
    int laps;
	struct node *next;
} node_t;

void race_state(int *id, size_t size);
node_t* createNode(int car);
void insertAtEnd(node_t** head, int car);
int racers(node_t* head, int id);
void displaylap(node_t** head);
void sortlist(node_t** head);

#endif