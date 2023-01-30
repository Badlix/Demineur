#include <iostream>
#include <cassert>
#include "grid.h"

using namespace std;

vector<vector<Cell>> Grid::initGrid() {
    // Initialisation of empty cells
    vector<vector<Cell>> cells = {};
    for (unsigned i (0) ; i < m_height; ++i) {
        cells.push_back({});
        for (unsigned j (0); j < m_width; ++j) {
            cells[i].push_back(Cell{j,i,0,true});
        }
    }

    // Implant bombs
    srand(time(NULL));
    unsigned bombsInGrid (0);
    Cell aCell;
    while (bombsInGrid != m_bombsNb) {
        aCell = m_cells[rand()%m_height][rand()%m_width];
        if (getCell(aCell.posX, aCell.posY).value == 9) continue;
        getCell(aCell.posX, aCell.posY).value = 9;
        ++bombsInGrid;
    }

    // change cell value depending of bombs proximity
    vector<Cell> nearCells = {};
    for (unsigned y (0); y < m_height; ++y) {
        for (unsigned x (0); x < m_width; ++x) {
            if (getCell(x, y).value == 9) {
                nearCells = getAllNearCell(getCell(x,y));
                for (Cell &cell : nearCells) {
                    if (cell.value < 9) ++cell.value;
                }
            }
        }
    }

    return cells;
}

Grid::Grid(const unsigned width, const unsigned height, const unsigned bombsNb) {
    m_width = width;
    m_height = height;
    m_bombsNb = bombsNb;
    //m_cells = initGrid();
    m_cells = {{Cell{0,0,1,false}, Cell{1,0,2,false}}, {Cell{0,1,3,false}, Cell{1,1,4,false}}};
}

Cell& Grid::getCell(const unsigned x, const unsigned y) {
    if (x >= m_width) throw out_of_range("x from getCell()");
    if (y >= m_height) throw out_of_range("y from getCell()");
    return m_cells[y][x];
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

vector<Cell>& Grid::getAllNearCell(const Cell &cell) {
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

void Grid::showCells() {
    cout << endl;
    for (vector<Cell> line : m_cells) {
        for (Cell cell : line) {
            cout << cell.value << ' ';
        }
        cout << endl;
    }
}


























