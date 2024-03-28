CC = gcc
CFLAGS := ${CFLAGS} -c -Wall
SOURCES = main.c mymath.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = calculator.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

run:
	./calculator.out
#
clean:
	rm -rf ./*.out
	rm -rf ./*.o