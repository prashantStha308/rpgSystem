# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -I./includes

# Directories
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
INCLUDE_DIR = ./includes

# Find all .cpp files recursively in src/ and subdirectories
SRC = $(shell find $(SRC_DIR) -type f -name "*.cpp") main.cpp

# Generate corresponding .o file paths inside build/
OBJ = $(patsubst ./%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Executable name
EXEC = rpg

# Default target
all: $(BIN_DIR)/$(EXEC)
	$(BIN_DIR)/$(EXEC)

# Link object files to create executable
$(BIN_DIR)/$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN_DIR)/$(EXEC)

# Compile .cpp files into .o files inside build/
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)  # Ensure subdirectories exist before compiling
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean up object files and executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
