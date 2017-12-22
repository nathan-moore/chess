include ./Makefile.inc

EXEC := board.exe
TESTOBJS :=
EXPANDED := $()#todo make a tester and put in actual numbers
.PHONY: exec test all

all:
	echo "$(ROOT)"
	echo "$(CC)"
	echo $(test)

exec:
	@make -C $(SRCDIR) $(EXEC)

board.exe:testobj
	$(CC) $(FLAGS) -o $(ODIR)/$(BOARDOBJ).o $(SRC)/$(BOARDOBJ).c
	$(CC) $(LINKFLAGS)

testobj:
	@for file in $(TESTOBJS); do \
		@make -c $(SRCDIR); \
	done
