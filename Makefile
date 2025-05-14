CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -g
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)
TARGET = build/payment_terminal_simulator

all: lint $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

lint:
	@betty $(SRC) include/*.h

clean:
	rm -rf build/*

.PHONY: all lint clean
