# This Makefile generates binaries for all days and puts them in the bin folder.
# You can just use "make" to compile everything all at once,
# or "make dayX" to compile a specific script.
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++17

SRC_DIR := .
BIN_DIR := bin

SOURCES := $(wildcard $(SRC_DIR)/day*.cpp)
BINARIES := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%, $(SOURCES))

# Default rule: build all binaries
all: $(BINARIES)

# Rule to compile individual binaries
$(BIN_DIR)/%: $(SRC_DIR)/%.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -rf $(BIN_DIR)

# Specific rule: compile a specific day (make dayX)
day%: $(BIN_DIR)/day%
	@echo "Built $<"

.PHONY: all clean
