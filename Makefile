help:
	@echo "targets debug small fast"

clean:
	rm -f linkedlist.o
	rm -f liblinkedlist.so

INCDIR=include/
SRCDIR=src/
SRCS=$(wildcard $(SRCDIR)*.c)
CC=gcc
CFLAGS=-Wall -Wextra -Wfatal-errors -D_POSIX_C_SOURCE=200809L\
	-std=c11

IFLAGS=-I$(INCDIR)

debug:	CFLAGS += -g -Og
small:	CFLAGS += -flto -Os -s
fast:	CFLAGS += -O2

debug:	objs
fast:	objs
small:	objs

objs:
	$(CC) -c -fPIC $(CFLAGS) $(IFLAGS) $(SRCS)
	$(CC) $(CFLAGS) -shared -o liblinkedlist.so linkedlist.o
