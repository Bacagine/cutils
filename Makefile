# Makefile for libcutils.so
# 
# Description: Makefile of the libcutils.so project
#
# Written by DEV_NAME <email@example.com>
# 
# Date: dd/mm/aaaa

ifndef _WIN32
TARGET     = libcutils.so
else 
TARGET     = libcutils.dll
endif

# Directories
SRCDIR     = src
INCDIR     = include
OBJDIR     = obj
LIBDIR     = lib
BINDIR     = bin
TESTDIR    = tests

# .c files
SRC        = $(wildcard $(SRCDIR)/*.c)

# .o files
OBJ        = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))

# libcutils.so
LIB        = $(LIBDIR)/$(TARGET)

# Compilation flags
LDFLAGS    = -L $(LIBDIR)
LDLIBS     = -lm
CFLAGS     = -I $(INCDIR) -Wall -Wextra 
ifdef _WIN32
CFLAGS     += -mwindows
LDLIBS     += -lwinpthread
else
LDLIBS     += -pthread
endif
DEBUGFLAGS = -g -O0 -DDEBUG_COMPILATION

# Compiler
CC         = gcc

ifdef DEBUG_COMPILATION
	CFLAGS += $(DEBUGFLAGS) 
	LDFLAGS += $(DEBUGFLAGS)
else
	CFLAGS += -O3
endif

all: distclean $(OBJDIR) $(LIBDIR) $(LIB)

$(LIB): $(OBJ)
	$(CC) -shared -o $@ $(OBJ) $(CFLAGS) $(LDFLAGS)

$(BINDIR):
	mkdir $@
$(LIBDIR):
	mkdir $@
$(OBJDIR):
	mkdir $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -fPIC -c $< -o $@ $(CFLAGS) $(LDLIBS)

clean:
	rm -rvf $(OBJDIR)

install: all
ifndef _WIN32
	./install.sh
else
	./install_windows.sh
endif

uninstall:
	./uninstall.sh

test: all $(BINDIR)
	$(CC) -o $(BINDIR)/file_len $(TESTDIR)/file_len.c $(CFLAGS) $(LDFLAGS) -lm -llibcutils
	$(CC) -o $(BINDIR)/getstr $(TESTDIR)/getstr.c $(CFLAGS) $(LDFLAGS) -lm -llibcutils

distclean: clean
	rm -rvf $(LIBDIR)
	rm -rvf $(BINDIR)
	
.PHONY: all clean install uninstall distclean

