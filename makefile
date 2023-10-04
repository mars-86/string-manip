###############################################################
#
INCDIR=lib
SRCDIR=lib
MAINDIR=.
CC=gcc
CFLAGS=-Wall -pedantic -I $(INCDIR)

###############################################################
# BUILDS FLAGS
DEBUG_FLAGS=-g
TEST_FLAGS=-fprofile-arcs -ftest-coverage
ANALISYS_FLAGS=-g

###############################################################
# DIRECTORIES
RELEASE_DIR=release
DEBUG_DIR=debug
OUTPUT_DIR=bin
OBJECT_DIR=obj
LIB_DIR=lib
TEST_DIR=__test__
COVERAGE_DIR=coverage
ANALISYS_DIR=analisys

DEBUG_OBJ_DIR=$(DEBUG_DIR)/$(OBJECT_DIR)
DEBUG_OUT_DIR=$(DEBUG_DIR)/$(OUTPUT_DIR)
RELEASE_OBJ_DIR=$(RELEASE_DIR)/$(OBJECT_DIR)
RELEASE_OUT_DIR=$(RELEASE_DIR)/$(OUTPUT_DIR)
TEST_OBJ_DIR=$(TEST_DIR)/$(OBJECT_DIR)
TEST_OUT_DIR=$(TEST_DIR)/$(OUTPUT_DIR)
TEST_COV_DIR=$(TEST_DIR)/$(COVERAGE_DIR)
ANALISYS_OBJ_DIR=$(ANALISYS_DIR)/$(OBJECT_DIR)
ANALISYS_OUT_DIR=$(ANALISYS_DIR)/$(OUTPUT_DIR)
ANALISYS_STATS_DIR=$(ANALISYS_DIR)/stats

###############################################################
# BINARY NAMES
DEBUG_OUT_NAME=str_manip.debug.out
RELEASE_OUT_NAME=str_manip.out
TEST_OUT_NAME=test.out
ANALISYS_OUT_NAME=analisys.out

###############################################################
# BUILD PATHS
DEBUG_BUILD=$(DEBUG_OUT_DIR)/$(DEBUG_OUT_NAME)
RELEASE_BUILD=$(RELEASE_OUT_DIR)/$(RELEASE_OUT_NAME)
TEST_BUILD=$(TEST_OUT_DIR)/$(TEST_OUT_NAME)
ANALISYS_BUILD=$(ANALISYS_OUT_DIR)/$(ANALISYS_OUT_NAME)

LIBS=

ANALISYS_TOOL=valgrind
MEMCHECK=valgrind --tool=memcheck -s --xtree-memory=allocs --xtree-memory-file=$(ANALISYS_STATS_DIR)/xtmemory.kcg.%p --xtree-leak=yes --xtree-leak-file=$(ANALISYS_STATS_DIR)/xtleak.kcg.%p
TRACING_PROFILER=valgrind --tool=cachegrind --cachegrind-out-file=$(ANALISYS_STATS_DIR)/cachegrind.out.%p
HEAP_PROFILER=valgrind --tool=massif --massif-out-file=$(ANALISYS_STATS_DIR)/massif.out.%p
TEST_ANALISYS_TOOL=$(shell type $(ANALISYS_TOOL))

_DEPS = byte_copy.h common.h str_char.h str_manip.h str_trim.h
DEPS = $(patsubst %,$(INCDIR)/%,$(_DEPS))

_OBJ = str_begins.o str_char.o str_ends.o str_include.o str_lowercase.o str_occurrence.o str_pad.o str_remove_char.o str_replace.o str_split.o str_trim.o str_uppercase.o

###############################################################
# CHOOSE BUILD TARGET
ifeq ($(BUILD),release)
$(info RELEASE)
OBJ = $(patsubst %,$(RELEASE_OBJ_DIR)/%,$(_OBJ))

all: build-release

else ifeq ($(BUILD),debug)
$(info DEBUG)
OBJ = $(patsubst %,$(DEBUG_OBJ_DIR)/%,$(_OBJ))

all: build-debug

else ifeq ($(BUILD),test)
$(info TEST)
OBJ = $(TEST_OBJ_DIR)/test.o
OBJ += $(patsubst %,$(TEST_OBJ_DIR)/%,$(_OBJ))

all: test

else ifeq ($(BUILD),memtest)
$(info MEMTEST)
ifneq ($(TEST_ANALISYS_TOOL),)
$(info valgrind installed)
# valgrind not installed
else
$(error valgrind not installed)
#valgrind installed
endif

OBJ = $(ANALISYS_OBJ_DIR)/test.o
OBJ += $(patsubst %,$(ANALISYS_OBJ_DIR)/%,$(_OBJ))

all: memtest

else

$(warning You must specify build target!)

endif

###############################################################
# DEBUG DIRECTIVES
$(DEBUG_OBJ_DIR)/%.o: $(MAINDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(DEBUG_FLAGS) $(CFLAGS)

$(DEBUG_OBJ_DIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(DEBUG_FLAGS) $(CFLAGS)

$(DEBUG_OBJ_DIR):
	mkdir -p $@

$(DEBUG_OUT_DIR):
	mkdir -p $@

$(DEBUG_BUILD): $(OBJ)
	$(CC) -o $@ $^ $(DEBUG_FLAGS) $(CFLAGS) $(LIBS)

###############################################################
# RELEASE DIREVTIVES
$(RELEASE_OBJ_DIR)/%.o: $(MAINDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(RELEASE_OBJ_DIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(RELEASE_OBJ_DIR):
	mkdir -p $@

$(RELEASE_OUT_DIR):
	mkdir -p $@

$(RELEASE_BUILD): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

###############################################################
# TEST DIRECTIVES
$(TEST_OBJ_DIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/test.c $(DEPS)
	$(CC) -c -o $@ $< $(TEST_FLAGS) $(CFLAGS)

$(TEST_OBJ_DIR):
	mkdir -p $@

$(TEST_OUT_DIR):
	mkdir -p $@

$(TEST_COV_DIR):
	mkdir -p $@

$(TEST_BUILD): $(OBJ)
	$(CC) -o $@ $^ $(TEST_FLAGS) $(CFLAGS) $(LIBS)

###############################################################
# ANALISYS DIRECTIVES
$(ANALISYS_OBJ_DIR)/%.o: $(SRCDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(ANALISYS_FLAGS) $(CFLAGS)

$(ANALISYS_OBJ_DIR)/%.o: $(TEST_DIR)/test.c $(DEPS)
	$(CC) -c -o $@ $< $(ANALISYS_FLAGS) $(CFLAGS)

$(ANALISYS_OBJ_DIR):
	mkdir -p $@

$(ANALISYS_OUT_DIR):
	mkdir -p $@

$(ANALISYS_STATS_DIR):
	mkdir -p $@

$(ANALISYS_BUILD): $(OBJ)
	$(CC) -o $@ $^ $(ANALISYS_FLAGS) $(CFLAGS) $(LIBS)

###############################################################
# BUILD RECIPES
build-debug: $(DEBUG_OBJ_DIR) $(DEBUG_OUT_DIR) $(DEBUG_BUILD)

build-release: $(RELEASE_OBJ_DIR) $(RELEASE_OUT_DIR) $(RELEASE_BUILD)

test: $(TEST_OBJ_DIR) $(TEST_OUT_DIR) $(TEST_COV_DIR) $(TEST_BUILD)
	# run the test, which will generate test.gcna and test.gcno
	./$(TEST_OUT_DIR)/$(TEST_OUT_NAME)
	# compute how test is covering
	gcov -c -p $(TEST_OBJ_DIR)/test
	# move output file in root to coverage folder
	mv *.gcov $(TEST_COV_DIR)

memtest: $(ANALISYS_OBJ_DIR) $(ANALISYS_OUT_DIR) $(ANALISYS_STATS_DIR) $(ANALISYS_BUILD)
	# run the analisys tools
	$(MEMCHECK) $(TEST_OUT_DIR)/$(ANALISYS_OUT_NAME)
	$(TRACING_PROFILER) $(TEST_OUT_DIR)/$(ANALISYS_OUT_NAME)
	$(HEAP_PROFILER) $(TEST_OUT_DIR)/$(ANALISYS_OUT_NAME)

###############################################################
# CLEAN OBJECT DIRECTORIES
.PHONY: clean

clean:
	rm -f $(DEBUG_OBJ_DIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(RELEASE_OBJ_DIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(TEST_OBJ_DIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(ANALISYS_OBJ_DIR)/*.o *~ core $(INCDIR)/*~
