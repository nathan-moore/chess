
SOURCES := board.cpp chess.cpp main.cpp piece.cpp
OBJECTSC := $(SOURCES:.cpp=.o)
HEADERSC := board.h chess.h piece.h


OBJECTS := $(addprefix $(ODIR),$(OBJECTSC))
HEADERS := $(addprefix $(INDIR),$(HEADERSC))

$(EXEC): $(OBJECTS)
	$(CC) -o  $(ROOT)board.exe $(OBJECTS) $(LINKFLAGS) $(FLAGS)

$(ODIR)%.o: $(SRCDIR)%.cpp $(HEADERS)
	$(COMPILE) -o $@ $< -c
	$(eval compiled += $@)


clean:
	rm  -f $(ODIR)*.o
