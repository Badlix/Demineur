#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include <vector>

class Grid {

public :

    /**
     * @brief Constructor for the class Grid
     * @param[in] width : Number of cells in a line of the grid
     * @param[in] height : Number of cells in a columon of the grid
     * @param BombsNb : Inital number of bombs in the grid
     */
    Grid(const unsigned &width, const unsigned &height, unsigned &bombsNb);

    /**
     * @brief get a cell from the grid at given coordinate
     * @param[in] x : coordinate x of the cell
     * @param[in] y : coordinate y of the cell
     * @return a cell
     */
    Cell getCell(const unsigned x, const unsigned y);

private:
    unsigned m_width;
    unsigned m_height;
    unsigned m_bombsNb;
    std::vector<std::vector<Cell>> m_cells;
};

#endif // GRID_H
