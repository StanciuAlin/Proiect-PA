CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=spanning_tree_Prim.c Minimum_spanning_tree.c menu.c generator.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=Minimum_spanning_tree

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@
