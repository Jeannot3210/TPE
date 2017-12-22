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
HEADER = .h #à compléter
LIB = /lib #à compléter

.PHONY : all clean distclean

all : .exe	#à compléter

.exe : .o	#à compléter
	$(CC) -o $@ $<

.o : .c	$(HEADER)	#à compléter
	$(CC) $(CPPFLAGS) -c $<

clean :
	rm *.o

distclean :
	-rm *.o	
	-rm *.c~
	-rm *.exe
	-rm *.h~
	-rm makefile~
