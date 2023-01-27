#ifndef GRID_H
#define GRID_H
#include "cell.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class Grid {

public :

    /**
     * @brief Create a grid with values depending on parameters
     * @return a vector of vector of cells ready to be used in a play
     */
    std::vector<std::vector<Cell>> initGrid();

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
    size_t m_width;
    size_t m_height;
    unsigned m_bombsNb;
    std::vector<std::vector<Cell>> m_cells;
};

#endif // GRID_H
