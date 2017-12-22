TOINCLUDE := ../Makefile.inc
include $(TOINCLUDE)

SOURCES := board.cpp chess.cpp main.cpp piece.cpp
OBJECTSC := $(SOURCES:.cpp=.o)
HEADERSC := board.h chess.h piece.h
FLAGS := $(COMPFLAGS) $(CPPFLAGS) $(DEFINES)
LINKFLAGS := 

board.exe: $(OBJECTS)
	$(CC) $(FLAGS) -o  board.exe $(OBJECTS)

$(ODIR)/%.o: $(SRCDIR)/%.cpp $(HEADERS)
	$(CC) $(FLAGS) -o $@ $< -c

clean:
	rm board.exe
	rm  $(ODIR)/*.o
