CC = gcc

CFLAGS = -Wall -Wextra -std=c11 -Iinclude

SRC = \
	src/main.c \
	src/history.c \
	src/lexer.c \
	src/token.c \
	src/parser.c \
	src/executor.c \
	src/builtin.c \
	src/expand.c

TARGET = shellforge

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -lreadline -o $(TARGET)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
