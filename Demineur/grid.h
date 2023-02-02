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
     * @brief Constructor for the class Grid
     * @param[in] width : Number of cells in a line of the grid
     * @param[in] height : Number of cells in a columon of the grid
     * @param[in] BombsNb : Inital number of bombs in the grid
     */
    Grid(const unsigned width, const unsigned height, const unsigned bombsNb);

    /**
     * @brief get a cell from the grid at given coordinate
     * @param[in] x : coordinate x of the cell
     * @param[in] y : coordinate y of the cell
     * @return a cell
     */
    Cell &getCell(const unsigned x, const unsigned y);

    /**
     * @brief getRightCell
     * @param[in] a cell
     * @return the cell next to the right
     */
    Cell &getRightCell(const Cell &cell);

    /**
     * @brief getLeftCell
     * @param[in] a cell
     * @return the cell next to the left
     */
    Cell &getLeftCell(const Cell &cell);

    /**
     * @brief getUpCell
     * @param[in] a cell
     * @return the cell above
     */
    Cell &getUpCell(const Cell &cell);

    /**
     * @brief getDownCell
     * @param[in] a cell
     * @return the cell under
     */
    Cell &getDownCell(const Cell &cell);

    /**
     * @brief get all the cell next to a certain cell
     * @param[in] a cell
     * @return a list between 3 and 8 cells
     */
    std::vector<Cell> getAllNearCells(const Cell &cell);

    /**
     * @brief check if there is a cell next to the right of a certain cell
     * @param[in] a cell
     * @return a booleen
     */
    bool isThereCellRight(const Cell &cell);

    /**
     * @brief check if there is a cell next to the left of a certain cell
     * @param[in] a cell
     * @return a booleen
     */
    bool isThereCellLeft(const Cell &cell);

    /**
     * @brief check if there is a cell above a certain cell
     * @param[in] a cell
     * @return a booleen
     */
    bool isThereCellUp(const Cell &cell);

    /**
     * @brief check if there is a cell under a certain cell
     * @param[in] a cell
     * @return a booleen
     */
    bool isThereCellDown(const Cell &cell);

    void makeCellVisible(Cell &cell);

    void putFlag(Cell &cell);

    /**
     * @brief show cells fo the grid
     */
    void showCells(bool allValue=true);

    /**
     * @brief get the width of the grid
     */
    size_t getWidth();

    /**
     * @brief get the height of the grid
     */
    size_t getHeight();

    /**
     * @brief get the number of bombs actually present on the grid
     */
    unsigned getBombNb();

    /**
     * @brief get the matrice of cells in the grid
     */
    std::vector<std::vector<Cell>> &getAllCells();

    unsigned getNbVisibleCell();

    void setNbVisibleCell(unsigned nb);

private:
    size_t m_width = 1;
    size_t m_height = 1;
    unsigned m_bombNb;
    unsigned m_visibleCell;
    std::vector<std::vector<Cell>> m_cells;

    /**
     * @brief Create a grid with values depending on parameters
     * @return a vector of vector of cells ready to be used in a play
     */
    std::vector<std::vector<Cell>> initGrid();
};

#endif // GRID_H
