CC = gcc
RELEASE_FLAGS = -Wall -O2 -std=c++11 -c
DEBUG_FLAGS = -g -D_DEBUG -Wall -std=c++11 -c
SOURCES = strset.cc strsetconst.cc
DEPS = strset.h strsetconst.h
OBJECTS = $(SOURCES:.cc=.o)

ifeq ($(debuglevel), 1)
    CXXFLAGS = $(DEBUG_FLAGS)
else
    CXXFLAGS = $(RELEASE_FLAGS)
endif

all: $(SOURCES) $(OBJECTS)

strset.o: strset.cc $(DEPS)
	$(CC) $(CXXFLAGS) $<

strsetconst.o: strsetconst.cc $(DEPS)
	$(CC) $(CXXFLAGS) $<

.PHONY: clean

clean:
	rm *.o
