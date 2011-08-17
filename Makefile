CXX = g++
CXXFLAGS = -Wall
CPPLIST = $(wildcard src/*.cpp)

all: $(CPPLIST)

src/%.cpp: force
	$(CXX) $(CXXFLAGS) -o bin/$* $@

force: ;
	
.PHONY: clean

clean:
	rm bin/*