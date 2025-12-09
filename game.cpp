#include "game.h"
#include <iostream>
#include <random>

Game::Game() {
  grid = Grid();
  blocks = GetAllBlocks();
  currBlock = GetRandomBlock();
  nextBlock = GetRandomBlock();
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
  if (IsBlockOutside()) {
    currBlock.Move(0, 1);
  }
}
void Game::MoveRight() {
  currBlock.Move(0, 1);
  if (IsBlockOutside()) {
    currBlock.Move(0, -1);
  }
}
void Game::MoveDown() {
  currBlock.Move(1, 0);
  if (IsBlockOutside()) {
    currBlock.Move(-1, 0);
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

void Game::RotateBlock() {
  currBlock.Rotate();
  // prevent future rotation to be outside
  if (IsBlockOutside()) {
    currBlock.UndoRotate();
  }
}
