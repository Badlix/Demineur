#include <iostream>
#include "game.h"

using namespace std;

void initGridValue(Grid &grid) {
    // Implant bombs
    srand(time(NULL));
    unsigned bombsInGrid (0);
    Cell aCell;
    while (bombsInGrid != grid.getBombNb()) {
        aCell = grid.getAllCells()[rand()%grid.getHeight()][rand()%grid.getWidth()];
        if (grid.getCell(aCell.posX, aCell.posY).value == 9) continue;
        grid.getCell(aCell.posX, aCell.posY).value = 9;
        ++bombsInGrid;
    }

    // change cell value depending of bombs proximity
    vector<Cell> nearCells = {};
    for (unsigned y (0); y < grid.getHeight(); ++y) {
        for (unsigned x (0); x < grid.getWidth(); ++x) {
            if (grid.getCell(x, y).value == 9) {
                nearCells = grid.getAllNearCells(grid.getCell(x,y));
                for (Cell &cell : nearCells) {
                     if (cell.value < 9) ++grid.getCell(cell.posX, cell.posY).value;
                }
            }
        }
    }
}

void revealNearCells(Cell &cell, Grid &grid) {
    if (cell.value > 0 || !cell.isHidden) {
        grid.makeCellVisible(cell);
        return;
    }
    vector<Cell> tmp = grid.getNearDirectCells(cell);
    grid.makeCellVisible(cell);
    if (tmp.size() == 0) return;
    if (tmp.size() >= 1) revealNearCells(grid.getCell(tmp[0].posX, tmp[0].posY), grid);
    if (tmp.size() >= 2) revealNearCells(grid.getCell(tmp[1].posX, tmp[1].posY), grid);
    if (tmp.size() >= 3) revealNearCells(grid.getCell(tmp[2].posX, tmp[2].posY), grid);
    if (tmp.size() == 4) revealNearCells(grid.getCell(tmp[3].posX, tmp[3].posY), grid);
    return;
}









