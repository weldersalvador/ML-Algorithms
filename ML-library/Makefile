CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

SRC_DIR  := core
SRCS     := main.cpp \
            $(SRC_DIR)/matrix.cpp

OBJS     := $(SRCS:.cpp=.o)
TARGET   := ml_library

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp $(SRC_DIR)/matrix.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(SRC_DIR)/matrix.o: $(SRC_DIR)/matrix.cpp $(SRC_DIR)/matrix.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild