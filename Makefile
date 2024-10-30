# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -I/usr/local/include
LDFLAGS = -L/usr/local/lib
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = RUN_EXE/bin
TEST_DIR = Tests
TARGET = $(BIN_DIR)/FeedMerger

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Test files and objects (optional)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/%_test.o, $(TEST_SRCS))
TEST_TARGET = $(BIN_DIR)/tests

# Default target: build main executable only
all: $(TARGET)

# Build main executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

# Build object files for main source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Build test executable (optional)
tests: CXXFLAGS += -lgtest -lgtest_main -pthread
tests: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS) $(OBJS) | $(BIN_DIR)
	$(CXX) $(LDFLAGS) -o $@ $^

# Build object files for test files
$(OBJ_DIR)/%_test.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Create directories if they don't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean tests
