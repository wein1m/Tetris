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
  // TODO: implement GAME_OVER state instead of gameOver bool
  enum GameState { PLAYING, SPAWN_DELAY, GAME_OVER };
  GameState state;
  bool gameOver;
  int score;
  Block nextBlock;

private:
  bool IsBlockOutside();
  void RotateBlock();
  void LockBlock();
  void Reset();
  bool IsBlockFits();
  std::vector<Block> blocks;
  Block currBlock;
  int points;
};
