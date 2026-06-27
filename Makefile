CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wno-unused-parameter -Wno-write-strings \
            -Wno-narrowing -Wno-sign-compare -Wno-unused-variable \
            -Wno-unused-but-set-variable -O2
LDLIBS   := -lglut -lGLU -lGL -lm

SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)
BIN := supershop

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

run: $(BIN)
	./$(BIN)
