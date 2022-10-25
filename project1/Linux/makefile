#
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC = g++

# define any compile-time flags
CFLAGS = -Wall -g -w

# define any directories containing header files other than /usr/include
#
INCLUDES = -I.

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
# LFLAGS = -L/home/newhall/lib  -L../lib

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
# LIBS = -lmylib -lm

# define the C source files
SRCS = slp.cpp main.cpp slp.h prog.h

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = slp.o main.o

# define the executable file 
MAIN = main

RM = rm

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

all:    $(MAIN) 
	@echo  Project1 has been compiled
	$(RM) *.o

# pattern rule that compiles every .cpp file into a .o file
# Pattern rules contain a '%' in the target. This '%' matches any nonempty string, and the other characters match themselves. 
# ‘%’ in a prerequisite of a pattern rule stands for the same stem that was matched by the ‘%’ in the target.
# $@ is an automatic variable that contains the target name
# $< The name of the first prerequisite

slp.o: slp.cpp slp.h prog.h
	$(CC) -c $(CFLAGS) $(INCLUDES) $< $(LFLAGS) $(LIBS)

main.o: main.cpp slp.h prog.h
	$(CC) -c $(CFLAGS) $(INCLUDES) $< $(LFLAGS) $(LIBS)

$(MAIN): main.o slp.o
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

clean:
	$(RM) *.o $(MAIN)
