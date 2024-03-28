CC = gcc
CFLAGS := ${CFLAGS} -c -Wall
SOURCES = main.c Occupation.c Human.c Handbook.c Utils.c Contacts.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = startbook.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

#.DEFAULT_GOAL := main.c
#
#all: clean run
#
#main.c:
#	gcc ./2/2.1/main.c ./2/2.1/Occupation.c ./2/2.1/Human.c ./2/2.1/Handbook.c -o ./2/2.1/startbook.out 
#
run:
	./startbook.out
#
clean:
	rm -rf ./*.out
	rm -rf ./*.o