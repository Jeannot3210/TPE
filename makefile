#
# Makefile
#
# @author Louis Goupil <louis.goupil@ecole.ensicaen.fr>
# @author Lutsen Alan <alan.lutsen@ecole.ensicaen.fr>
#
# ENSICAEN
# 6, Boulevard Maréchal Juin
# F-14050 Caen Cedex France
#
# This file is owned by ENSICAEN students.
# No portion of this document may be reproduced, copied
# or revised without written permission of the authors.

#
# v.0.0.1
#

CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
HI = ../include/image.h
HM = ../include/moments.h
LIB = /lib #à compléter

.PHONY : all clean distclean

all : image.o	#à compléter

main.exe : image.o	#à compléter
	$(CC) -o $@ $<

.o : .c	$(HI)	#à compléter
	$(CC) $(CPPFLAGS) -c $<

image.o : image.c	$(HI)	#à compléter
	$(CC) $(CPPFLAGS) -c $<

clean :
	rm *.o

distclean :
	-rm *.o	
	-rm *.c~
	-rm *.exe
	-rm *.h~
	-rm makefile~
