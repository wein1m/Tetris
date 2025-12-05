.PHONY: all clean run

PROJECT ?= game
RAYLIB_PATH ?= C:/raylib/raylib
CXX ?= g++
BUILD ?= Release

SRC_DIR := ./
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:.cpp=.o)
OUT := $(PROJECT).exe

CXXFLAGS := -std=c++14 -I"$(RAYLIB_PATH)/src" -I"$(RAYLIB_PATH)/src/external"
ifeq ($(BUILD),Debug)
CXXFLAGS += -g -O0 -DDEBUG
else
CXXFLAGS += -O2
endif

LDFLAGS := -L"$(RAYLIB_PATH)/src"
LDLIBS := -lraylib -lopengl32 -lgdi32 -lwinmm

all: $(OUT)

# compile .cpp -> .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# link
$(OUT): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT) $(OBJS)
