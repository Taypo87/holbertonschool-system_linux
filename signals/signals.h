#ifndef SINGALS_H
#define SINGALS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int handle_signal(void);
void handle_sigint(int sig);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void sigaction_handler(int sig);
void (*current_handler_sigaction(void))(int);
void trace_handler(int sig, siginfo_t *siginfo, void *context);
int trace_signal_sender(void);
void handle_sigint_once(int sig);

#endif
