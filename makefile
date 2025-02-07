# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files
SRC = $(wildcard ./src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = rpg

# Default target
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)
	./$(EXEC)

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)
