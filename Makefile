TOINCLUDE := ./Makefile.inc
include $(TOINCLUDE)

TESTFILES := pawnTest.exe
.PHONY: exec clean

#makes the chess game executable
exec:
	@$(MAKE) -C $(SRCDIR) $(EXEC)

$(TESTFILES):
	@$(MAKE) -C $(TESTDIR) $@
	./$@

clean:
	rm -f $(EXEC)
	rm -f $(TESTFILES)
	make -C $(SRCDIR) clean
