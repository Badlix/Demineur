#include "draw.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/rectangle.h"

void drawCell(MinGL &window, nsGraphics::Vec2D pos, Cell &cell) {
    window << nsShape::Rectangle(pos+(2,2), pos+(46,46), nsGraphics::KBlack);
}
