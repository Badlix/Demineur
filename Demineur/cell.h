#ifndef CELL_H
#define CELL_H

struct Cell {
    unsigned posX;
    unsigned posY;
    unsigned value;
    bool isHidden;
    bool hasFlag;
};

// List of value :
// - 0, ..., 8 : normal cell values
// - 9 : bombs
// - 10 : flag

#endif // CELL_H
