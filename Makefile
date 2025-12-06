.PHONY: all clean run

PROJECT ?= game
RAYLIB_PATH ?= C:/raylib/raylib
CXX ?= g++
BUILD ?= Release

SRC_DIR := ./
OBJ_DIR := obj

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
OUT := $(PROJECT).exe

CXXFLAGS := -std=c++14 -I"$(RAYLIB_PATH)/src" -I"$(RAYLIB_PATH)/src/external"

ifeq ($(BUILD),Debug)
CXXFLAGS += -g -O0 -DDEBUG
else
CXXFLAGS += -O2
endif

LDFLAGS := -L"$(RAYLIB_PATH)/src"
LDLIBS := -lraylib -lopengl32 -lgdi32 -lwinmm

all: $(OBJ_DIR) $(OUT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# compile .cpp -> .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# link
$(OUT): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT) $(OBJ_DIR)/*.o
