CC = g++
CXXFLAGS = -Wall -O2 -std=c++11
SOURCES = quaternion.cpp
DEPS = quaternion.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(DEPS)
	$(CC) $(CXXFLAGS) -c $<

run_test: test.cpp
	$(CC) $(CXXFLAGS) -o run_test $<



.PHONY: clean

clean:
	rm *.o *~ *.*~ run_test
