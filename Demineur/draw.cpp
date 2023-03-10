#include "draw.h"
#include "grid.h"
#include "game.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/rectangle.h"
#include "mingl/shape/line.h"
#include "mingl/gui/text.h"
#include "mingl/gui/sprite.h"

using namespace nsGraphics;

nsGraphics::RGBAcolor gris2 = nsGraphics::RGBAcolor(175,175,175);

void drawCell(MinGL &window, nsGraphics::Vec2D pos, Cell &cell) {
    if (cell.isHidden) {
        window << nsShape::Rectangle(pos, pos+Vec2D{30,3}, KWhite);
        window << nsShape::Rectangle(pos, pos+Vec2D{3,30}, KWhite);
        window << nsShape::Rectangle(pos+Vec2D{3,3}, pos+Vec2D{27,27}, KLightGrey);
        window << nsShape::Rectangle(pos+Vec2D{1,29}, pos+Vec2D{30,30}, KGrey);
        window << nsShape::Rectangle(pos+Vec2D{2,28}, pos+Vec2D{30,29}, KGrey);
        window << nsShape::Rectangle(pos+Vec2D{3,27}, pos+Vec2D{30,28}, KGrey);
        window << nsShape::Rectangle(pos+Vec2D{27,3}, pos+Vec2D{28,30}, KGrey);
        window << nsShape::Rectangle(pos+Vec2D{28,2}, pos+Vec2D{29,30}, KGrey);
        window << nsShape::Rectangle(pos+Vec2D{29,1}, pos+Vec2D{30,30}, KGrey);
    } else {
        window << nsShape::Rectangle(pos, pos+Vec2D{30,30}, KGrey);
        window << nsShape::Rectangle(pos+Vec2D{1,1}, pos+Vec2D{29,29}, KLightGrey);
        window << nsGui::Text(pos+Vec2D(10,22), std::to_string(cell.value), whichNumberColor(cell.value), nsGui::GlutFont::BITMAP_HELVETICA_18);
    }
}

void drawGrid(MinGL &window, Grid &grid) {
    for (size_t y(0); y < grid.getHeight(); ++y) {
        for (size_t x(0); x < grid.getWidth(); ++x) {
            drawCell(window, nsGraphics::Vec2D{x*30,y*30} + beginOfGrid, grid.getCell(x,y));
        }
    }
}

RGBAcolor whichNumberColor(unsigned number) {
    switch(number) {
    case 0:
        return KLightGrey;
    case 1:
        return KBlue;
    case 2:
        return KGreen;
    case 3:
        return KRed;
    case 4:
        return KNavy;
    case 5:
        return KMaroon;
    case 6:
        return KTeal;
    case 7:
        return KBlack;
    }
    return KGrey;
}

std::pair<unsigned, unsigned> convertCordToIndex(unsigned x, unsigned y) {
    unsigned indX = (x - beginOfGrid.getX())/30;
    unsigned indY = (y - beginOfGrid.getY())/30;
    return std::make_pair(indX, indY);
}

void events(MinGL &window, Grid &grid)
{
    std::pair<unsigned, unsigned> ind;
    while (window.getEventManager().hasEvent())
    {
        const nsEvent::Event_t actualEvent = window.getEventManager().pullEvent();
        if (actualEvent.eventType == nsEvent::EventType_t::MouseClick) {
            ind = convertCordToIndex(actualEvent.eventData.clickData.x, actualEvent.eventData.clickData.y);
            if (ind.first < grid.getWidth() && ind.second < grid.getHeight()) {
                if (actualEvent.eventData.clickData.button == 0) { // left click
                    //grid.makeCellVisible(grid.getCell(ind.first, ind.second));
                    revealNearCells(grid.getCell(ind.first, ind.second), grid);
                } else if (actualEvent.eventData.clickData.button == 2) { // right click
                    grid.putFlag(grid.getCell(ind.first, ind.second));
                }
            }
        }
    }
}
