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
  void HandleInput();
  void MoveLeft();
  void MoveRight();
  void MoveDown();
  double spawnDelayStart;
  enum GameState { PLAYING, SPAWN_DELAY };

  GameState state;

private:
  bool IsBlockOutside();
  void RotateBlock();
  void LockBlock();
  std::vector<Block> blocks;
  Block currBlock;
  Block nextBlock;
};
