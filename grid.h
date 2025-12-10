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
  bool IsCellEmpty(int row, int col);
  int ClearFullRows();
  int grid[20][10];

private:
  int numRows, numCols, cellSize;
  bool IsRowFull(int row);
  void ClearRow(int row);
  void MoveRowDown(int row, int numRow);
  std::vector<Color> colors;
};
