#include "game.h"
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
