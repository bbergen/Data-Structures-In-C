# Bryan's Generic Makefile

#define compiler
CC=gcc
CFLAGS=-Wall -g 

#define executable
MAIN=lab3

#define libs
LIBS=

#define source
SRC=$(wildcard *.c)
OBJS=$(SRC:.c=.o)

#compile main target
$(MAIN): $(OBJS)
				$(CC) $(OBJS) -o $(MAIN) $(LIBS)

#compile object files
%.o:%.cpp
				$(CC) -c $(CFLAGS) $< -o $@ $(LIBS)

#remove .o's and executable
clean:
				$(RM) -f $(MAIN) $(OBJS)


