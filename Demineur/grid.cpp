#include <iostream>
#include <cassert>
#include "grid.h"

using namespace std;

std::vector<std::vector<Cell>> Grid::initGrid() {
    // Initialisation of empty cells
    std::vector<std::vector<Cell>> cells = {};
    for (unsigned i (0) ; i < m_height; ++i) {
        for (unsigned j (0); j < m_width; ++j) {
            cells[i].push_back(Cell{j,i,0,true});
        }
        cells.push_back({});
    }

    // Implant bombs
    srand (time(NULL));
    unsigned bombsInGrid (0);
    Cell aCell;
    while (bombsInGrid != m_bombsNb) {
        aCell
    }

    return cells;
}

Grid::Grid(const unsigned &width, const unsigned &height, unsigned &bombsNb) {
    m_width = width;
    m_height = height;
    m_bombsNb = bombsNb;
    m_cells = initGrid();
}

Cell Grid::getCell(const unsigned x, const unsigned y) {
    if (x < 0 or x >= m_width) throw out_of_range("x from getCell()");
    if (y < 0 or y >= m_width) throw out_of_range("y from getCell()");
    return m_cells[y][x];
}
