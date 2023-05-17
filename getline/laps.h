#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
/**
* node - struct that holds
*
*/
typedef struct node
{
	int car;
	int laps;
	struct node *next;
} node_t;

void race_state(int *id, size_t size);
node_t *createNode(int car);
node_t *insertCarInOrder(node_t *head, int car);
void displaylap(node_t *head);


#endif
