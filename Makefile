CC = g++
CXXFLAGS = -Wall -O2 -std=c++11
SOURCES = quaternion_sequence.cpp
DEPS = quaternion.h quaternion_sequence.h
OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(OBJECTS)

$(OBJECTS): $(SOURCES) $(DEPS)
	$(CC) $(CXXFLAGS) -c $<

quat: test.cpp $(DEPS)
	$(CC) $(CXXFLAGS) -o quat_test $<

seq: test2.cpp $(DEPS)
	$(CC) $(CXXFLAGS) $(OBJECTS) -o seq_test $<

non: test3.cpp $(DEPS)
	$(CC) $(CXXFLAGS) $<


.PHONY: clean

clean:
	rm *.o *~ *.*~ quat_test seq_test test
