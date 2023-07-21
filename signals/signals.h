#ifndef SINGALS_H
#define SINGALS_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <singal.h>

int handle_signal(void);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);



#endif