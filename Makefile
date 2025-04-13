CC = gcc

CFLAGS = -g -Wall -O3 -Iinclude

LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRCS = src/main.c src/loop.c

all:
	$(CC) $(SRCS) $(CFLAGS) -o game $(LDFLAGS)
clean:
	rm -f game