#include "multithreading.h"
#include "list.h"

task_t *create_task(task_entry_t entry, void *param)
{
    task_t *task;
    pthread_mutex_t lock;

    task = malloc(sizeof(task));
    task->status = PENDING;
    task->result = NULL;
    pthread_mutex_init(&lock);
    return(task);

}
void destroy_task(task_t *task)
{
    if (task->result != NULL)
    {
        list_destroy(task->result);
        free(task->result);
        task->result = NULL
        free(task);
    }
}
void *exec_tasks(list_t const *tasks)
{

}