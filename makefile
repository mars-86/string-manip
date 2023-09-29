INCDIR=lib
SRCDIR=lib
MAINDIR=.
CC=gcc

ifeq ($(BUILD),release)

CFLAGS=-Wall -pedantic -I $(INCDIR)

else

CFLAGS=-g -Wall -pedantic -I $(INCDIR)

endif

RELEASEDIR=release
DEBUGDIR=debug
OUTPUTDIR=bin
OBJECTDIR=obj
LIBDIR=lib

DEBUGNAME=str_manip.debug.out
RELEASENAME=str_manip.out

DEBUGOBJDIR=$(DEBUGDIR)/$(OBJECTDIR)
DEBUGOUTDIR=$(DEBUGDIR)/$(OUTPUTDIR)
RELEASEOBJDIR=$(RELEASEDIR)/$(OBJECTDIR)
RELEASEOUTDIR=$(RELEASEDIR)/$(OUTPUTDIR)

DEBUGBUILD=$(DEBUGOUTDIR)/$(DEBUGNAME)
RELEASEBUILD=$(RELEASEOUTDIR)/$(RELEASENAME)

LIBS=

_DEPS = byte_copy.h common.h str_char.h str_manip.h str_trim.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ = main.o str_begins.o str_char.o str_ends.o str_include.o str_lowercase.o str_occurrence.o str_pad.o str_remove_char.o str_replace.o str_split.o str_trim.o str_uppercase.o

ifeq ($(BUILD),release)

OBJ = $(patsubst %,$(RELEASEOBJDIR)/%,$(_OBJ))

all: build-release

else

OBJ = $(patsubst %,$(DEBUGOBJDIR)/%,$(_OBJ))

all: build-debug

endif

$(DEBUGOBJDIR)/%.o: $(MAINDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(DEBUGOBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(DEBUGOBJDIR):
	mkdir -p $@

$(DEBUGOUTDIR):
	mkdir -p $@

$(DEBUGBUILD): $(OBJ)
	$(CC) -o $@ $^ $(CDEBUGFLAGS) $(CFLAGS) $(LIBS)

$(RELEASEOBJDIR)/%.o: $(MAINDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(RELEASEOBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(RELEASEOBJDIR):
	mkdir -p $@

$(RELEASEOUTDIR):
	mkdir -p $@

$(RELEASEBUILD): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


build-debug: $(DEBUGOBJDIR) $(DEBUGOUTDIR) $(DEBUGBUILD)

build-release: $(RELEASEOBJDIR) $(RELEASEOUTDIR) $(RELEASEBUILD)


.PHONY: clean

clean:
	rm -f $(DEBUGOBJDIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(RELEASEOBJDIR)/*.o *~ core $(INCDIR)/*~
