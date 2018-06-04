CC= gcc
/cflags = -Wall -O0
MAIN = lab6
OBJS = lab6.o lab6a.o
all : $(MAIN)

$(MAIN) : $(OBJS) lab6.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

lab6.o : lab6.c lab6.h
	$(CC) $(CFLAGS) -c lab6.c

lab6a.o : lab6a.c lab6.h
	$(CC) $(CFLAGS) -c lab6a.c

clean :
	rm *.o $(MAIN) core

