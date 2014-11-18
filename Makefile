CC = g++
CXXFLAGS = -Wall -O2 -std=c++11 -c
SOURCES = quaternion.cpp
DEPS = quaternion.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(DEPS)
	$(CC) $(CXXFLAGS) $<

test: test.cpp
	$(CC) $(CXXFLAGS) $<



.PHONY: clean

clean:
	rm *.o *~ *.*~
