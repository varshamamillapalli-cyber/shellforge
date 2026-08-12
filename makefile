CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = \
src/main.c \
src/history.c \
src/lexer.c \
src/token.c

TARGET = shellforge

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -lreadline -o $(TARGET)

clean:
	rm -f $(TARGET)
