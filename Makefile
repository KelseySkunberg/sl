#==========================================
#    Makefile: makefile for sl 5.1
#	Copyright 1993, 1998, 2014
#                 Toyoda Masashi
#		  (mtoyoda@acm.org)
#	Last Modified: 2014/03/31
#==========================================
# The OG ^...lots of code is gone. Cat is now a train.
# His name is Jimmy.

CC=gcc
CFLAGS=-O -Wall

all: sl

sl: sl.c sl.h
	$(CC) $(CFLAGS) -o sl sl.c -lncurses

clean:
	rm -f sl

distclean: clean
