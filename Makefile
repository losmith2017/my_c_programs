TARGET = fahrenheit-celsius find_longest_line
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall

.PHONY: default all clean mytest mytest2

default: $(TARGET)
all: default

OBJECTS := $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS := $(wildcard *.h)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): % : %.o 
	$(CC) -o $@ $< -Wall $(LIBS)


GOOFY := -lfoo -lbar

CFLAGS := $(GOOFY2) -g

CFLAGS2 = $(GOOFY2) -g

GOOFY2 = -lmath

mytest: 
	@echo $(GOOFY)
	@echo $(CFLAGS)

mytest2:
	@echo $(CFLAGS2)

clean:
	-rm -f *.o
	-rm -f $(TARGET)
