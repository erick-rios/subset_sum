CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
BUILD_DIR = build

all: $(BUILD_DIR)/test

$(BUILD_DIR)/test: $(BUILD_DIR)/TestSubsetSum.o $(BUILD_DIR)/SubsetSum.o
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/SubsetSum.o: src/SubsetSum.cpp src/SubsetSum.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/TestSubsetSum.o: src/TestSubsetSum.cpp src/SubsetSum.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

