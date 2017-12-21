CC := g++

ODIR := ../objects
SRCDIR := ../src
INDIR = ../include

$(shell mkdir -p $(ODIR) >/dev/null)

COMPFLAGS = -I $(INDIR)
CPPFLAGS := -Wall -Wshadow -Werror -g -std=gnu++11
DEFINES := -D DEBUG

SOURCES := board.cpp chess.cpp main.cpp piece.cpp
OBJECTSC := $(SOURCES:.cpp=.o)
HEADERSC := board.h chess.h piece.h
FLAGS := $(COMPFLAGS) $(CPPFLAGS) $(DEFINES)

OBJECTS := $(addprefix $(ODIR)/,$(OBJECTSC))
HEADERS := $(addprefix $(INDIR)/,$(HEADERSC))

board.exe: $(OBJECTS) $(HEADERS) Makefile
	$(CC) $(FLAGS) -o  board.exe $(OBJECTS)

$(ODIR)/%.o: %.cpp $(INDIR)/$(HEADERS) Makefile
	$(CC) $(FLAGS) -o $@ $< -c

clean:
	del board.exe
	del $(ODIR)/*.o
