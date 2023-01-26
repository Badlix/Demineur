#include <iostream>
#include <cassert>
#include "grid.h"

using namespace std;

Grid::Grid(const unsigned &width, const unsigned &height, unsigned &bombsNb) {
    m_width = width;
    m_height = height;
    m_bombsNb = bombsNb;
}

Cell Grid::getCell(const unsigned x, const unsigned y) {
    assert(x >= 0 or x < m_width);
    return m_cells[y][x];
}
