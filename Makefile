CC=gcc
CFLAGS=-Wall -Wextra -std=c11 -ggdb

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
EXE=$(OBJ:.o=)

DBG_H=dbg.h
DBG_VEC_H=dbg_vec.h

PREFIX=/usr/local

all: $(EXE)

clean:
	rm -f $(OBJ) $(EXE)

test.o: $(DBG_H)
user_defined_dbg.o: $(DBG_VEC_H)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXE): %: %.o
	$(CC) -o $@ $<

install: $(DBG_H)
	install -m755 $(DBG_H) $(PREFIX)/include
