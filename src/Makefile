CC = g++
COMPFLAGS = -I$(INDIR)
CPPFLAGS = -Wall -Wshadow -Werror -g
SOURCES = board.cpp chess.cpp main.cpp piece.cpp
OBJECTSC = $(SOURCES:.cpp=.o)
HEADERSC = board.h chess.h piece.h
FLAGS = $(COMPFLAGS) $(CPPFLAGS)

ODIR = ../objects
SRCDIR = ../src
INDIR = ../include

OBJECTS = $(addprefix $(ODIR)/,$(OBJECTSC))
HEADERS = $(addprefix $(INDIR)/,$(HEADERSC))

board.exe: $(OBJECTS) $(HEADERS)
	$(CC) $(FLAGS) -o  board.exe $(OBJECTS)

$(ODIR)/%.o: %.cpp $(INDIR)/$(HEADERS)
	$(CC) $(FLAGS) -o $(ODIR)/$@ $< -c

clean:
	del board.exe
	del *.o
