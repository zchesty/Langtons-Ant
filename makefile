CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

SRCS = Ant.cpp inValHelpers.cpp Menu.cpp antSim.cpp 

HEADERS = Ant.hpp inValHelpers.hpp Menu.hpp

antSim: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${SRCS} -o antSim

clean:
	rm antSim
