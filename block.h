#pragma once
#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  void Draw();
  int id;
  std::map<int, std::vector<Position>> cells;

private:
  int cellSize;
  int rotationState;
  std::vector<Color> colors;
};
