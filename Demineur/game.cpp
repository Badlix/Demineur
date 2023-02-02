#include <iostream>
#include "mingl/graphics/vec2d.h"
#include "mingl/mingl.h"
#include "thread"
#include "game.h"

using namespace std;

void launchGame(const string difficulty) {
    Grid grid = createGrid(difficulty);
    pair<unsigned, unsigned> windowSize = {grid.getWidth()*30, grid.getHeight()*30+20};
    MinGL window("Demineur - " + to_string(grid.getWidth() + "x" + to_string(grid.getHeight() + " - " + to_string(grid.getBombNb() + " bombs"))),
                 nsGraphics::Vec2D(windowSize.first, windowSize.second),
                 nsGraphics::Vec2D(window.getWindowSize().getX()/2-windowSize.first/2, window.getWindowSize().getY()/2-windowSize.second/2),
                 nsGraphics::RGBAcolor(200,200,200));
    window.initGlut();
    window.initGraphic();
    chrono::microseconds frameTime = chrono::microseconds::zero();
    while (window.open()) {
        window.clearScreen();
        drawGrid(window, grid);
        events(window, grid);
        window.finishFrame();
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    return;
}

Grid createGrid(const string difficulty) {
    Grid grid;
    if (difficulty == "easy") {
        grid = Grid(8,8,16);
    } else if (difficulty == "medium") {
        grid = Grid(16,16,40);
    } else if (difficulty == "hard") {
        grid = Grid(35,16,99);
    } else {
        grid = Grid(10,10,10);
    }
    initGridValue(grid);
    return grid;
}

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
    vector<Cell> tmp = grid.getAllNearCells(cell);
    grid.makeCellVisible(cell);
    grid.setNbVisibleCell(grid.getNbVisibleCell()-1);
    for (Cell c : tmp) {
        revealNearCells(grid.getCell(c.posX, c.posY), grid);
    }
    return;
}

void checkEndGame() {

}








