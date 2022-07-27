.SSP:all

CXX = g++
CXXFLAGS = -O3
LDFLAGS = -lm -lglut -lGLU -lGL

all:line polygon

line:line.cpp
	$(CXX) -o line ${CXXFLAGS} $^ $(LDFLAGS)

polygon:polygon.cpp
	$(CXX) -o polygon ${CXXFLAGS} $^ $(LDFLAGS)

.SSP:clean
clean:
	rm -f *.o line polygon