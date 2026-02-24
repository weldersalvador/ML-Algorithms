CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2 -Icore -Ioptim -Imodels

TARGET := ml_library

# Pega TODOS os .cpp do projeto (inclusive subpastas)
SRCS := $(wildcard *.cpp) $(wildcard */*.cpp)

# Gera os .o correspondentes
OBJS := $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra genérica para qualquer .cpp virar .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

.PHONY: all clean rebuild