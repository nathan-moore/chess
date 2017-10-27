CC = g++
CPPFLAGS = -Wall -Wshadow -Werror -g
SOURCES = board.cpp chess.cpp main.cpp piece.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = board.h chess.h piece.h


board.exe: $(OBJECTS) $(HEADERS)
	g++ -o $(CPPGLAGS) board.exe $(OBJECTS)

clean:
	del board.exe
	del *.o
