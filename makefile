INCDIR=lib
SRCDIR=lib
MAINDIR=.
CC=gcc
CFLAGS=-Wall -pedantic -I $(INCDIR)

DEBUGFLAGS=-g
TESTFLAGS=-fprofile-arcs -ftest-coverage

RELEASEDIR=release
DEBUGDIR=debug
OUTPUTDIR=bin
OBJECTDIR=obj
LIBDIR=lib
TESTDIR=__test__

DEBUGNAME=str_manip.debug.out
RELEASENAME=str_manip.out
TESTNAME=test.out

DEBUGOBJDIR=$(DEBUGDIR)/$(OBJECTDIR)
DEBUGOUTDIR=$(DEBUGDIR)/$(OUTPUTDIR)
RELEASEOBJDIR=$(RELEASEDIR)/$(OBJECTDIR)
RELEASEOUTDIR=$(RELEASEDIR)/$(OUTPUTDIR)
TESTOBJDIR=$(TESTDIR)/$(OBJECTDIR)
TESTOUTDIR=$(TESTDIR)/$(OUTPUTDIR)

DEBUGBUILD=$(DEBUGOUTDIR)/$(DEBUGNAME)
RELEASEBUILD=$(RELEASEOUTDIR)/$(RELEASENAME)
TESTBUILD=$(TESTOUTDIR)/$(TESTNAME)

LIBS=

_DEPS = byte_copy.h common.h str_char.h str_manip.h str_trim.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ = str_begins.o str_char.o str_ends.o str_include.o str_lowercase.o str_occurrence.o str_pad.o str_remove_char.o str_replace.o str_split.o str_trim.o str_uppercase.o

ifeq ($(BUILD),release)

OBJ = $(patsubst %,$(RELEASEOBJDIR)/%,$(_OBJ))

all: build-release

else ifeq ($(BUILD),debug)

OBJ = $(patsubst %,$(DEBUGOBJDIR)/%,$(_OBJ))

all: build-debug

else ifeq ($(BUILD),test)

OBJ = $(TESTOBJDIR)/test.o
OBJ += $(patsubst %,$(TESTOBJDIR)/%,$(_OBJ))

all: test

else

# You must specify build target
all: test

endif

$(DEBUGOBJDIR)/%.o: $(MAINDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(DEBUGFLAGS) $(CFLAGS)

$(DEBUGOBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(DEBUGFLAGS) $(CFLAGS)

$(DEBUGOBJDIR):
	mkdir -p $@

$(DEBUGOUTDIR):
	mkdir -p $@

$(DEBUGBUILD): $(OBJ)
	$(CC) -o $@ $^ $(DEBUGFLAGS) $(CFLAGS) $(LIBS)

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

$(TESTOBJDIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TESTOBJDIR)/%.o: $(TESTDIR)/test.c $(DEPS)
	$(CC) -c -o $@ $< $(TESTFLAGS) $(CFLAGS)

$(TESTBUILD): $(OBJ)
	$(CC) -o $@ $^ $(TESTFLAGS) $(CFLAGS) $(LIBS)

$(TESTOBJDIR):
	mkdir -p $@

$(TESTOUTDIR):
	mkdir -p $@

build-debug: $(DEBUGOBJDIR) $(DEBUGOUTDIR) $(DEBUGBUILD)

build-release: $(RELEASEOBJDIR) $(RELEASEOUTDIR) $(RELEASEBUILD)

test: $(TESTOBJDIR) $(TESTOUTDIR) $(TESTBUILD)
	# run the test, which will generate test-counter.gcna and test.gcno
	./$(TESTOUTDIR)/$(TESTNAME)
	# compute how test is covering
	gcov -c -p $(TESTOBJDIR)/test __test__/test

.PHONY: clean

clean:
	rm -f $(DEBUGOBJDIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(RELEASEOBJDIR)/*.o *~ core $(INCDIR)/*~
