CC = gcc
CFLAGS = -g -Wall               # (built-in variable) compiling C programs
OBJS = main.o foo.o bar.o       # (built-in variable) extra flags to givce to CC
TARGET = app.out

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)           # $@ : (automatic variables) current target name

main.o : foo.h bar.h main.c
foo.o : foo.h foo.c
bar.o : bar.h bar.c

clean:
	rm -f *.o
	rm -f $(TARGET)
