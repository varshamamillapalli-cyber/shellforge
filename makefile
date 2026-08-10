CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude
LIBS = -lreadline

shellforge: src/history.c src/main.c
	gcc $(CFLAGS) src/history.c src/main.c $(LIBS) -o shellforge

clean:
	rm -f shellforge
