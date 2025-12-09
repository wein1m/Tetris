#pragma once
#include "colors.h"
#include "position.h"
#include <map>
#include <vector>

class Block {
public:
  Block();
  void Draw();
  void Move(int rows, int cols);
  std::vector<Position> GetCellPosition();
  int id;
  std::map<int, std::vector<Position>> cells;
  void Rotate();
  void UndoRotate();

private:
  int cellSize;
  int rotationState;
  std::vector<Color> colors;
  int rowOffset, colOffset;
};
