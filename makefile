# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall $(INCLUDE_DIRS)

# Directories
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
INCLUDE_DIR = ./includes

# Recursively find all .cpp files inside src/
SRC = $(shell find $(SRC_DIR) -type f -name "*.cpp") main.cpp

# Generate .o file paths inside build/ (keeping subdirectory structure)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Executable name
EXEC = rpg

# Include all subdirectories under includes/
INCLUDE_DIRS := $(shell find $(INCLUDE_DIR) -type d | sed 's/^/-I/')

# Default target
all: $(BIN_DIR)/$(EXEC)
	$(BIN_DIR)/$(EXEC)

# Link object files to create executable
$(BIN_DIR)/$(EXEC): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(BIN_DIR)/$(EXEC)

# Compile .cpp files into .o files inside build/ while maintaining folder structure
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)  # Ensure subdirectories exist before compiling
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
