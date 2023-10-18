CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -g

# Task 4
todo_api_0: 4-main.o shared.o
	$(CC) $(CFLAGS) -o todo_api_0 4-main.o shared.o

4-main.o: 4-main.c socket.h
	$(CC) $(CFLAGS) -c 4-main.c

shared.o: shared.c socket.h
	$(CC) $(CFLAGS) -c shared.c

# Task 5
task5: 5-main.o shared.o
	$(CC) $(CFLAGS) -o task5 5-main.o shared.o

5-main.o: 5-main.c socket.h
	$(CC) $(CFLAGS) -c 5-main.c

# Task 6, 7, 8, and 9 can be added similarly

clean:
	rm -f *.o task4 task5

.PHONY: clean
