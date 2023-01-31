#ifndef DRAW_H
#define DRAW_H
#include "cell.h"
#include "mingl/mingl.h"
#include "mingl/graphics/vec2d.h"

void drawCell(MinGL &window, nsGraphics::Vec2D pos, Cell &cell);

void getCell(int x, int y);

void events(MinGL &window);

#endif // DRAW_H