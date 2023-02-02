#ifndef GAME_H
#define GAME_H
#include "grid.h"

void launchGame(const std::string difficulty);

Grid createGrid(const std::string difficulty);

void initGridValue(Grid &grid);

void revealNearCells(Cell &cell, Grid &grid);

#endif // GAME_H
