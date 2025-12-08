#pragma once
#include "blocks.cpp"
#include "grid.h"

class Game {
public:
  Game();
  Grid grid;
  Block GetRandomBlock();
  void Draw();
  std::vector<Block> GetAllBlocks();

private:
  std::vector<Block> blocks;
  Block currBlock;
  Block nextBlock;
};
