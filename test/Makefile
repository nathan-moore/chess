
SRCFILES := $(SRCPAWNOBJS)

LPAWNOBJS := test.o
SRCPAWNOBJS := board.o piece.o
empty := adf

FPATHSRC := $(addprefix $(ODIR), $(SRCPAWNOBJS))
PAWNALLOBJS := $(addprefix $(ODIR), $(LPAWNOBJS)) $(FPATHSRC)

pawnTest.exe:$(PAWNALLOBJS) $(ROOT)pawnTest.exe
	$(SILENT)if [ $(words $(compiled)) -gt 0 ]; then \
	$(COMPILE) $(LINKFLAGS) $(PAWNALLOBJS) -o $(ROOT)pawnTest.exe;\
	fi

#make sure files in the src directory are up to date
$(FPATHSRC):
	$(call recurse,$(SRCDIR),$@)

#deals with local files
$(ODIR)%.o:%.cpp $(LHEADERS)
	$(COMPILE) -c $^ -o $@
	$(eval compiled += $@)

$(ROOT)pawnTest.exe:
	$(eval compiled += $@)

.PHONY:$(FPATHSRC)
