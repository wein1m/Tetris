#pragma once
#include "blocks.cpp"
#include "grid.h"

class Game {
public:
  Game();
  Grid grid;
  Block GetRandomBlock();
  void Draw();
  void HandleInput();
  void MoveLeft();
  void MoveRight();
  void MoveDown();
  std::vector<Block> GetAllBlocks();

private:
  bool IsBlockOutside();
  void RotateBlock();
  std::vector<Block> blocks;
  Block currBlock;
  Block nextBlock;
};
