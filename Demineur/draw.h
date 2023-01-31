#ifndef DRAW_H
#define DRAW_H
#include "cell.h"
#include "grid.h"
#include "mingl/mingl.h"
#include "mingl/graphics/rgbacolor.h"
#include "mingl/graphics/vec2d.h"

void drawCell(MinGL &window, nsGraphics::Vec2D pos, Cell &cell);

nsGraphics::RGBAcolor whichNumberColor(unsigned number);

std::pair<unsigned, unsigned> getInd(unsigned x, unsigned y);

void events(MinGL &window, Grid &grid);

#endif // DRAW_H
