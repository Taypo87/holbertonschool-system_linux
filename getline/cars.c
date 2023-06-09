#include "laps.h"

void sortlist(node_t **head)
{
node_t *sorted;
node_t *current = *head;

while (current != NULL)
{
node_t *next = current->next;

if (sorted == NULL || current->car < sorted->car)
{
current->next = sorted;
sorted = current;
}
else
{
node_t *temp = sorted;
while (temp->next != NULL && temp->next->car < current->car)
{
temp = temp->next;
}
current->next = temp->next;
temp->next = current;
}
current = next;
}
*head = sorted;
}

void race_state(int *id, size_t size)
{
static node_t *head;
int addracer = 0;
if (size == 0)
{
node_t *current = head;
while (current != NULL)
{
node_t *temp = current;
current = current->next;
free(temp);
}
return ();
}
if (head == NULL)
{
for (int i = 0; i < size; i++)
{
insertAtEnd(&head, id[i]);
printf("Car %i has joined the race!\n", id[i]);
}
}
else
{
for (int i = 0; i < size; i++)
{
addracer = racers(head, id[i]);
if (addracer == 0)
{
insertAtEnd(&head, id[i]);
printf("Car %i has joined the race!\n", id[i]);
}
}
}
sortlist(&head);
printf("Race state:\n");
node_t *current = head;
while (current != NULL)
{
printf("Car %i [%i laps]\n", current->car, current->laps);
current = current->next;
}
}
int racers(node_t *head, int id)
{
while (head != NULL)
{
if (id == head->car)
{
head->laps = head->laps + 1;
return (1);
}
head = head->next;
}
return (0);
}
node_t *createNode(int car)
{
node_t *newNode = (node_t *)malloc(sizeof(node_t));
newNode->car = car;
newNode->next = NULL;
return (newNode);
}

void insertAtEnd(node_t **head, int car)
{
node_t *newNode = createNode(car);
if (*head == NULL)
{
*head = newNode;
return;
}
node_t *temp = *head;
while (temp->next != NULL)
{
temp = temp->next;
}
temp->next = newNode;
}
