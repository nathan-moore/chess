ROOT := $(dir $(realpath $(MAKEFILES)))

#root includes / already
ODIR = $(ROOT)objects/
SRCDIR = $(ROOT)src/
INDIR = $(ROOT)include/
TESTDIR = $(ROOT)test/

CC := g++
COMPFLAGS = -I $(INDIR)
CPPFLAGS := -Wall -Wshadow -Werror -g -std=gnu++11
DEFINES := #-D DEBUG
FLAGS := $(COMPFLAGS) $(CPPFLAGS) $(DEFINES)
LINKFLAGS :=

COMPILE = $(CC) $(FLAGS)

#make sure object directory exists
$(shell mkdir -p $(ODIR) >/dev/null)

EXEC := $(ROOT)exec.exe

#determines if make will be visible
SILENT :=@

recurse = $(SILENT)$(MAKE) -C $(1) $(2)
workAdded = compiled += $(1)
