help:
	@echo "targets debug release"

clean:
	rm -f linkedlist.o
	rm -f liblinkedlist.so

INCDIR=include/
SRCDIR=src/
SRCS=$(wildcard $(SRCDIR)*.c)

CFLAGS=-Wall -Wextra -Wfatal-errors -D_POSIX_C_SOURCE=200809L\
	-std=c11

IFLAGS=-I$(INCDIR)

debug:	CFLAGS += -g -Og
release:	CFLAGS += -flto -Os -s

debug:	objs
release:	objs


objs:
	gcc -c -fPIC $(CFLAGS) $(IFLAGS) $(SRCS)
	gcc $(CFLAGS) -shared -o liblinkedlist.so linkedlist.o
