#pragma once
#include <raylib.h>
#include <vector>

class Grid {
public:
  Grid();
  void Initialize();
  void Print();
  void Draw();
  bool IsCellOutside(int row, int col);
  int grid[20][10];

private:
  int numRows, numCols, cellSize;
  std::vector<Color> colors;
};
