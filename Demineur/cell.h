#ifndef CELL_H
#define CELL_H
#include "mingl/graphics/vec2d.h"

struct Cell {
    unsigned posX;
    unsigned posY;
    unsigned value;
    bool isHidden;
    bool hasFlag;
};

const nsGraphics::Vec2D beginOfGrid(0,50);

// List of value :
// - 0, ..., 8 : normal cell values
// - 9 : bombs
// - 10 : flag

#endif // CELL_H
