.SSP:all 

CXX = g++
CXXFLAGS = -O3
LDFLAGS = -lm -lglut -lGLU -lGL
TARGET = main

all:main

main:main.cpp
	$(CXX) -o ${TARGET} ${CXXFLAGS} $^ $(LDFLAGS)


.SSP:clean
clean:
	rm -f *.o main