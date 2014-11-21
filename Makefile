CC = g++
CXXFLAGS = -Wall -O2 -std=c++11
SOURCES = quaternion_sequence.cpp
DEPS = quaternion.h quaternion_sequence.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(DEPS)
	$(CC) $(CXXFLAGS) -c $<

run_test: test.cpp $(DEPS)
	$(CC) $(CXXFLAGS) -o run_test $<

test: test2.cpp $(DEPS)
	$(CC) $(CXXFLAGS) $(OBJECTS) $<

test3: test3.cpp $(DEPS)
	$(CC) $(CXXFLAGS) $<


.PHONY: clean

clean:
	rm *.o *~ *.*~ run_test
