TOINCLUDE := Makefile.mk
MAKEFILES :=  $(dir $(realpath $(TOINCLUDE)))$(TOINCLUDE)
MAKEFLAGS += --no-print-directory

include $(MAKEFILES)

export compiled 

TESTFILES := pawnTest.exe
.PHONY: exec clean $(TESTFILES)

#makes the chess game executable
exec:
	$(call recurse,$(SRCDIR),$(EXEC))

$(TESTFILES):
	$(call recurse,$(TESTDIR),$@)
	./$@

clean:
	rm -f $(EXEC)
	rm -f $(TESTFILES)
	make -C $(SRCDIR) clean
