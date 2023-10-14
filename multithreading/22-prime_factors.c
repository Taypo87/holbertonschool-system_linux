#include "multithreading.h"
#include "list.h"

/*
* create_task - initializes a task node
* @entry: function pointer to be used
* @param: parameters for the task
* Return: the initialized node
*/
task_t *create_task(task_entry_t entry, void *param)
{
	task_t *task;

	task = malloc(sizeof(task_t));
	task->status = PENDING;
	task->param = param;
	task->entry = entry;
	task->result = NULL;
	pthread_mutex_init(&task->lock, NULL);
	return(task);

}

/*
* destroy_task - frees a list of tasks
* @task: the list to free
*/
void destroy_task(task_t *task)
{
	if (task->result != NULL)
	{
		list_destroy(task->result, free);
		free((list_t *) task->result);
		task->result = NULL;
		free(task);
	}
}

/*
* exec_tasks - executes a task with the given paramaters
* @tasks: list of tasks to complete
*/
void *exec_tasks(list_t const *tasks)
{
	task_t *task = NULL;
	node_t *node = NULL;
	int i = 0;
	node = tasks->head;

	while (node)
	{
		task = node->content;
		if (pthread_mutex_trylock(&task->lock))
		{
			if (task->status == PENDING)
			{
				task->status = STARTED;
				tprintf("[%02d] Started\n", i);
				task->result = task->entry(task->param);
				tprintf("[%02d] Success\n", i);
				if (task->result == NULL)
					task->status = FAILURE;
				else
					task->status = SUCCESS;
			}
			pthread_mutex_unlock(&task->lock);
			node = node->next;
			i++;
		} 

	}
	return (NULL);
}