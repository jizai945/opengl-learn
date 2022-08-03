.SSP:all

CXX = g++
CXXFLAGS = -O3
LDFLAGS = -lm -lglut -lGLU -lGL

all:main

main:main.cpp
	$(CXX) -o main ${CXXFLAGS} $^ $(LDFLAGS)


.SSP:clean
clean:
	rm -f *.o main