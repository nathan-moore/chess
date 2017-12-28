TOINCLUDE := ../Makefile.inc
include $(TOINCLUDE)

SRCFILES = $(SRCPAWNOBJS)
LOCALFILES = $(LPAWNOBJS)

.PHONY:$(TESTS)

LPAWNOBJS := test.o
SRCPAWNOBJS := board.o
PAWNALLOBJS := $(addprefix $(ODIR), $(LPAWNOBJS) $(SRCPAWNOBJS))

pawnTest.exe:$(PAWNALLOBJS)
	$(COMPILE) $(LINKFLAGS) $(PAWNALLOBJS) -o $(ROOT)pawnTest.exe

#make sure files in the src directory are up to date
$(addprefix $(ODIR),$(SRCFILES)):
	@$(MAKE) -C $(SRCDIR) $@

#deals with local files
.SECONDEXPANSION =
$(ODIR)%.o:%.cpp $(LHEADERS)
	$(COMPILE) -c $^ -o $@
