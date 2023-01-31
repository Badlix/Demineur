#include "draw.h"
#include "mingl/graphics/vec2d.h"
#include "mingl/shape/rectangle.h"
#include "mingl/gui/text.h"

nsGraphics::RGBAcolor gris2 = nsGraphics::RGBAcolor(175,175,175);

void drawCell(MinGL &window, nsGraphics::Vec2D pos, Cell &cell) {
    window << nsShape::Rectangle(pos+nsGraphics::Vec2D{1,1}, pos+nsGraphics::Vec2D{24,24}, gris2);
    if (!cell.isHidden) {
        window << nsGui::Text(pos+nsGraphics::Vec2D(8,17), std::to_string(cell.value), nsGraphics::KWhite, nsGui::GlutFont::BITMAP_9_BY_15);
    }
}

void getCell(int x, int y) {
    int cellX = x;
    int cellY = y;
    std::cout << cellX << " - " << cellY << std::endl;
}

void events(MinGL &window)
{
    // On vérifie chaque évènement de la queue d'évènements
    while (window.getEventManager().hasEvent())
    {
        const nsEvent::Event_t actualEvent = window.getEventManager().pullEvent();

        if (actualEvent.eventType == nsEvent::EventType_t::MouseClick) {
            std::cout << "ok" << std::endl;
            getCell(actualEvent.eventData.clickData.x, actualEvent.eventData.clickData.y);        // Il s'agit d'un mouvement de souris
        }
    }
}
