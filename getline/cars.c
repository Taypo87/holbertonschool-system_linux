#include "laps.h"

void displaylap(node_t* head)
{
    printf("Race state:\n");
    while (head != NULL)
    {
        printf("Car %i [%i laps]\n", head->car, head->laps);
        head = head->next;
    }
}

void race_state(int *id, size_t size)
{
    //static int laps = 0;
    static node_t *head = NULL;
    int addracer = 0;
    if (size == 0)
    {
        //free_list(new);
        return;
    }
    if (head == NULL)
    {
        for(int i = 0; i < size; i++)
        {
            insertAtEnd(&head, id[i]);
            printf("Car %i has joined the race!\n", id[i]);

        }
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            addracer = racers(head, id[i]);
            if (addracer == 0)
            {
                insertAtEnd(&head, id[i]);
                printf("Car %i has joined the race!\n", id[i]);
            }
        }
    }
    displaylap(head);
    //laps++;
    //printf("laps = %i\n", laps);
}














int racers(node_t* head, int id)
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
void displayList(node_t* head)
{
    node_t* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->car);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to create a new node
node_t* createNode(int car)
{
    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->car = car;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(node_t** head, int car)
{
    node_t* newNode = createNode(car);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node_t* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

