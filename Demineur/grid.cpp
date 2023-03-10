#include <iostream>
#include <cassert>
#include "grid.h"
#include "game.h"

using namespace std;

vector<vector<Cell>> Grid::initGrid() {
    // Initialisation of empty cells
    vector<vector<Cell>> cells = {};
    for (unsigned y(0); y < m_height; ++y) {
        cells.push_back({});
        for (unsigned x(0); x < m_width; ++x) {
            cells[y].push_back(Cell{x,y,0,true,false});
        }
    }
    return cells;
}

Grid::Grid(const unsigned width, const unsigned height, const unsigned bombsNb) {
    m_width = width;
    m_height = height;
    m_bombNb = bombsNb;
    m_cells = initGrid();
    m_visibleCell = 0;
}

Cell& Grid::getCell(const unsigned x, const unsigned y) {
    if (x >= m_width) throw out_of_range("x from getCell()");
    if (y >= m_height) throw out_of_range("y from getCell()");
    return m_cells[y][x];
}

vector<Cell> Grid::getAllNearCells(const Cell &cell) {
    vector<Cell> nearCells = {};
    // up
    if (isThereCellUp(cell)) {
        nearCells.push_back(getUpCell(cell));
        // up-right
        if (isThereCellRight(cell)) nearCells.push_back(getUpCell(getRightCell(cell)));
        // up-left
        if (isThereCellLeft(cell)) nearCells.push_back(getUpCell(getLeftCell(cell)));
    }
    // down
    if (isThereCellDown(cell)) {
        nearCells.push_back(getDownCell(cell));
        // down-right
        if (isThereCellRight(cell)) nearCells.push_back(getDownCell(getRightCell(cell)));
        // down-left
        if (isThereCellLeft(cell)) nearCells.push_back(getDownCell(getLeftCell(cell)));
    }
    // right
    if (isThereCellRight(cell)) nearCells.push_back(getRightCell(cell));
    // left
    if (isThereCellLeft(cell)) nearCells.push_back(getLeftCell(cell));
    return nearCells;
}


Cell& Grid::getRightCell(const Cell &cell) {
    return m_cells[cell.posY][cell.posX+1];
}

Cell& Grid::getLeftCell(const Cell &cell) {
    return m_cells[cell.posY][cell.posX-1];
}

Cell& Grid::getUpCell(const Cell &cell) {
    return m_cells[cell.posY-1][cell.posX];
}

Cell& Grid::getDownCell(const Cell &cell) {
    return m_cells[cell.posY+1][cell.posX];
}

bool Grid::isThereCellRight(const Cell &cell) {
    return (cell.posX < m_width-1);
}

bool Grid::isThereCellLeft(const Cell &cell) {
    return (cell.posX > 0);
}

bool Grid::isThereCellUp(const Cell &cell) {
    return (cell.posY > 0);
}

bool Grid::isThereCellDown(const Cell &cell) {
    return (cell.posY < m_height-1);
}

void Grid::makeCellVisible(Cell &cell) {
    if (cell.isHidden) {
        cell.isHidden = false;
        setNbVisibleCell(getNbVisibleCell()+1);
    }
}

void Grid::putFlag(Cell &cell) {
    if (!cell.hasFlag) cell.hasFlag = true;
}

void Grid::showCells(bool allValue) {
    cout << endl;
    for (const vector<Cell> &line : m_cells) {
        for (Cell cell : line) {
            if (allValue) cout << cell.value << ' ';
            else if (cell.isHidden) cout << "- ";
            else cout << cell.value << ' ';
        }
        cout << endl;
    }
}

size_t Grid::getWidth() {
    return m_width;
}

size_t Grid::getHeight() {
    return m_height;
}

unsigned Grid::getBombNb() {
    return m_bombNb;
}

std::vector<std::vector<Cell>> &Grid::getAllCells() {
    return m_cells;
}

unsigned Grid::getNbVisibleCell() {
    return m_visibleCell;
}

void Grid::setNbVisibleCell(unsigned nb) {
    m_visibleCell = nb;
}



















