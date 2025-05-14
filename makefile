# Usage: make FILE=path/to/file.cpp

CXX = g++
CXXFLAGS = -DLOCAL -std=c++20

all:
	$(CXX) $(CXXFLAGS) "$(FILE)"
