# GNU Makefile
# Author: Emil Gedda

OBJDIR = ../bin
SRCS = $(wildcard  *.cpp)
OBJS = $(addprefix ../bin/, $(SRCS:.cpp=))
CXX = clang++
CXXFLAGS = -O2 -march=native -Wall -Werror -std=c++17

.PHONY: all clean

all: $(OBJS)

$(OBJS): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OBJDIR)
