# Executable names:
EXE = final
TEST = test

# Add all object files needed for compiling:
EXE_OBJ = main.o
OBJS = main.o Airport.o

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Use the cs225 makefile template:
include cs225.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

Airport.o: main.cpp Airport.cpp
	$(CXX) $(CXXFLAGS) main.cpp Airport.cpp

route.o: main.cpp route.cpp
	$(CXX) $(CXXFLAGS) main.cpp route.cpp

coordinate.o: main.cpp coordinate.cpp
	$(CXX) $(CXXFLAGS) main.cpp coordinate.cpp

clean:
	-rm -f *.o $(EXENAME) test