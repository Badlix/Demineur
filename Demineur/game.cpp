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
                nearCells = grid.getAllNearCell(grid.getCell(x,y));
                for (Cell &cell : nearCells) {
                     if (cell.value < 9) ++grid.getCell(cell.posX, cell.posY).value;
                }
            }
        }
    }
}
