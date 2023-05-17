#include "laps.h"
/**
* displaylap - displays the lap number for each car in the race
* @head: the head node to a linked list of cars
* Return: Void
*/
void displaylap(node_t *head)
{
	printf("Race state:\n");
	while (head != NULL)
	{
		printf("Car %i [%i laps]\n", head->car, head->laps);
		head = head->next;
	}
}
/**
* createNode - creates a new node for the cars linked list
* @car: the id of the car being created
* Return: pointer to the new node
*/
node_t *createNode(int car)
{
	node_t *newNode = (node_t *)malloc(sizeof(node_t));

	newNode->car = car;
	newNode->laps = 0;
	newNode->next = NULL;
	return (newNode);
}
/**
* insertCarInOrder - adds a new car to the race, and updates cars laps
* @head: first node in the list of cars
* @car: id of the car being added or updated
* Return: pointer to the updated list
*/
node_t *insertCarInOrder(node_t *head, int car)
{
	node_t *newNode = createNode(car);
	node_t *current = head;

	if (head == NULL || car < head->car)
	{
		newNode->next = head;
		return (newNode);
	}

	while (current->next != NULL && car > current->next->car)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;
	return (head);
}
/**
* race_state - calls helper functions to create and track cars
* @id: array containing car numbers
* @size: number of cars in id
* Return: Void
*/
void race_state(int *id, size_t size)
{
	size_t i;
	static node_t *head;

	if (size == 0)
	{
		while (head != NULL)
		{
			node_t *temp = head;

			head = head->next;
			free(temp);
		}
		return;
	}
	for (i = 0; i < size; i++)
	{
		int addracer = 0;
		node_t *current = head;

		while (current != NULL)
		{
			if (id[i] == current->car)
			{
				current->laps++;
				addracer = 1;
				break;
			}
			current = current->next;
		}
		if (!addracer)
		{
			head = insertCarInOrder(head, id[i]);
			printf("Car %i has joined the race!\n", id[i]);
		}
	}
	displaylap(head);
}
