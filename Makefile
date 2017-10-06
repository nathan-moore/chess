CC = g++
CPPFLAGS = -Wall
SOURCEs = board.cpp chess.cpp main.cpp
OBJECTS = $(SOURCES:.cpp:.o)
HEADERS = board.h chess.h piece.h

.PHONY = run

run: $(OBJECTS) $(HEADERS)
	g++ -o board $(OBJECTS)
