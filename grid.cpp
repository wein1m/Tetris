#include "grid.h"
#include "colors.h"
#include <iostream>

Grid::Grid() {
  numRows = 20;
  numCols = 10;
  cellSize = 30;
  Initialize();
  colors = GetCellColors();
}

void Grid::Initialize() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      grid[row][col] = 0;
    }
  }
}

void Grid::Print() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      std::cout << grid[row][col] << " ";
    }
    std::cout << std::endl;
  }
}

void Grid::Draw() {
  for (int row = 0; row < numRows; row++) {
    for (int col = 0; col < numCols; col++) {
      int cellValue = grid[row][col];
      // +1 for margin, -1 to keep  the size the same (cuz we add 1 for margin)
      DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1,
                    cellSize - 1, colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(int row, int col) {
  // if it's inside the grid, return false
  if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
    return false;
  }
  return true;
}

bool Grid::IsCellEmpty(int row, int col) {
  if (grid[row][col] == 0) {
    return true;
  }
  return false;
}
