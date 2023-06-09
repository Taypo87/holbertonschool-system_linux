#ifndef LAPS_H
#define LAPS_H

#include <stdio.h>
#include <stdlib.h>
/**
* struct node - struct that holds
* @car: id for each car in the race
* @laps: how many laps the car has completed
* @next: pointer to the next node in the list
* Description: singly linked list struct
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
