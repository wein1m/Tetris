#include "game.h"
#include <iostream>
#include <random>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();
  currBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
  state = PLAYING;
  spawnDelayStart = 0.0;
}

// make sure every blocks appeared exactly once in every round
Block Game::GetRandomBlock() {
  if (blocks.empty()) {
    blocks = GetAllBlocks();
  }
  int randIndex = rand() % blocks.size();
  Block block = blocks[randIndex];
  // moves the iterator forward randIndex positions to point at the selected
  // block
  blocks.erase(blocks.begin() + randIndex);
  return block;
}

std::vector<Block> Game::GetAllBlocks() {
  return {IBlock(), JBlock(), IBlock(), OBlock(), SBlock(), ZBlock(), TBlock()};
}

void Game::Draw() {
  grid.Draw();
  currBlock.Draw();
}

void Game::HandleInput() {
  int keyPressed = GetKeyPressed();

  switch (keyPressed) {
  case KEY_LEFT:
    MoveLeft();
    break;
  case KEY_RIGHT:
    MoveRight();
    break;
  case KEY_DOWN:
    MoveDown();
    break;
  case KEY_UP:
    RotateBlock();
    break;
  }
}

void Game::MoveLeft() {
  currBlock.Move(0, -1);
  if (IsBlockOutside() || !IsBlockFits()) {
    currBlock.Move(0, 1);
  }
}
void Game::MoveRight() {
  currBlock.Move(0, 1);
  if (IsBlockOutside() || !IsBlockFits()) {
    currBlock.Move(0, -1);
  }
}
void Game::MoveDown() {
  currBlock.Move(1, 0);
  if (IsBlockOutside() || !IsBlockFits()) {
    currBlock.Move(-1, 0);
    LockBlock();
  }
}

void Game::RotateBlock() {
  currBlock.Rotate();
  // prevent future rotation to be outside
  if (IsBlockOutside() || !IsBlockFits()) {
    currBlock.UndoRotate();
  }
}

bool Game::IsBlockOutside() {
  std::vector<Position> tiles = currBlock.GetCellPosition();
  for (Position item : tiles) {
    if (grid.IsCellOutside(item.row, item.col)) {
      return true;
    }
  }
  return false;
}

void Game::LockBlock() {
  std::vector<Position> tiles = currBlock.GetCellPosition();

  for (Position item : tiles) {
    grid.grid[item.row][item.col] = currBlock.id;
  }

  currBlock = nextBlock;
  nextBlock = GetRandomBlock();
  grid.ClearFullRows();

  spawnDelayStart = GetTime();
  state = SPAWN_DELAY;
}

bool Game::IsBlockFits() {
  std::vector<Position> tiles = currBlock.GetCellPosition();
  for (Position item : tiles) {
    if (!grid.IsCellEmpty(item.row, item.col)) {
      return false;
    }
  }
  return true;
}
