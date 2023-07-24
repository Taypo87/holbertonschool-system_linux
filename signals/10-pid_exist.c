#include <signal.h>
#include <sys/types.h>
/**
* pid_exist - checks if a process exists for a given pid
* @pid: process id
* Return: 1 if process exists, 0 otherwise
*/
int pid_exist(pid_t pid)
{
	return (kill(pid, 0) == 0) ? 1 : 0;
}
