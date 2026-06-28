CXX      := g++
CXXFLAGS := -std=c++17 -Isrc -Wall -Wno-unused-parameter -Wno-write-strings \
            -Wno-narrowing -Wno-sign-compare -Wno-unused-variable \
            -Wno-unused-but-set-variable -O2

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
CXXFLAGS += -DGL_SILENCE_DEPRECATION
LDLIBS   := -framework GLUT -framework OpenGL -lm
else
LDLIBS   := -lglut -lGLU -lGL -lm
endif

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
BIN := supershop

.PHONY: all clean run check-deps

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)

run: $(BIN)
	./$(BIN)

check-deps:
	@command -v $(CXX) >/dev/null || { echo "Missing C++ compiler: $(CXX)"; exit 1; }
ifeq ($(UNAME_S),Darwin)
	@test -f "$$(xcrun --show-sdk-path)/System/Library/Frameworks/GLUT.framework/Headers/glut.h" || { echo "Missing GLUT framework. Run: xcode-select --install"; exit 1; }
	@test -f "$$(xcrun --show-sdk-path)/System/Library/Frameworks/OpenGL.framework/Headers/gl.h" || { echo "Missing OpenGL framework. Run: xcode-select --install"; exit 1; }
else
	@printf '#include <GL/glut.h>\nint main(){return 0;}\n' | $(CXX) -x c++ - $(LDLIBS) -o /tmp/supershop-glut-check >/dev/null 2>&1 || { echo "Missing OpenGL/GLUT development libraries. On Ubuntu/Debian run: sudo apt install build-essential freeglut3-dev libglu1-mesa-dev"; exit 1; }
	@rm -f /tmp/supershop-glut-check
endif
	@echo "Dependencies look ready."
