include ../Makefile.inc

TESTS = pawn
EXEC = ../BoardExec

.PHONY:$(TESTS)

.SECONDEXPANSION =

$(TESTS):$$@ $(EXEC)
	$(MAKE) -C $@

clean:
	/bin/rm -f *.o
	/bin/rm -f *.out
