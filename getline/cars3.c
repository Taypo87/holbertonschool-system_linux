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
* free_list - frees a linked list
* @head: head node of a linked list
* Return: Null
*/
void free_list(node_t *head)
{
	while (head != NULL)
	{
		node_t *temp = head;

		head = head->next;
		free(temp);
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
* addOrUpdateCar - adds a new car to the race, and updates cars laps
* @head: first node in the list of cars
* @car: id of the car being added or updated
* Return: pointer to the updated list
*/
node_t *addOrUpdateCar(node_t *head, int car)
{
	node_t *current = head;
	node_t *prev = NULL;

	while (current != NULL)
	{
		if (current->car == car)
		{
			current->laps++;
			return (head);
		}
		prev = current;
		current = current->next;
	}

	node_t *newNode = createNode(car);

	newNode->next = head;
	if (prev != NULL)
	{
		prev->next = newNode;
	} else
	{
		head = newNode;
	}
	printf("Car %i has joined the race!\n", car);

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
	static node_t *head;

	if (size == 0)
	{
		free_list(head);
		head = NULL;
		return;
	}
	if (head == NULL)
	{
		for (int i = 0; i < size; i++)
		{
			head = addOrUpdateCar(head, id[i]);
		}
    } else
    {
        rac
    }
	displaylap(head);
}
