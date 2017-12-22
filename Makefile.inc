ROOT := $(dir $(realpath $(TOINCLUDE)))

CC := g++
COMPFLAGS = -I $(INDIR)
CPPFLAGS := -Wall -Wshadow -Werror -g -std=gnu++11
DEFINES := -D DEBUG

ODIR := $(ROOT)objects
SRCDIR := $(ROOT)src
INDIR = $(ROOT)include

$(shell mkdir -p $(ODIR) >/dev/null)

OBJECTS := $(addprefix $(ODIR)/,$(OBJECTSC))
HEADERS := $(addprefix $(INDIR)/,$(HEADERSC))

all:
	echo $(ROOT)
