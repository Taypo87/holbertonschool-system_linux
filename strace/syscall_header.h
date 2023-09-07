#ifndef SYSCALL_HEADER
#define SYSCALL_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <linux/ptrace.h>


int check_arg(int argc, char** argv);

#endif