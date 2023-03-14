#define FPS_LIMIT 60
#include <iostream>
#include <mingl/mingl.h>
#include <thread>
#include "mingl/shape/rectangle.h"
#include "mingl/gui/text.h"
#include "mingl/gui/sprite.h"
#include "cell.h"
#include "grid.h"
#include "game.h"
#include "draw.h"

using namespace std;

int main()
{
//    bool isApplicationRunning (true);
//    Grid grid = Grid(9,9,10);
//    initGridValue(grid);

    MinGL window("Demineur", nsGraphics::Vec2D(450,750), nsGraphics::Vec2D(550,100), nsGraphics::RGBAcolor(175,175,175));
    window.initGlut();
    window.initGraphic();

    chrono::microseconds frameTime = chrono::microseconds::zero();
    string whatIsNextPage = "";
    while (window.isOpen()) {
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();
        window.clearScreen();
        window << nsShape::Rectangle(nsGraphics::Vec2D(50,250), nsGraphics::Vec2D(400,325), nsGraphics::RGBAcolor(150,150,150));
        window << nsGui::Sprite("../Demineur/assets/easy.si2", nsGraphics::Vec2D(125,262));
        window << nsShape::Rectangle(nsGraphics::Vec2D(50,350), nsGraphics::Vec2D(400,425), nsGraphics::RGBAcolor(150,150,150));
        window << nsGui::Sprite("../Demineur/assets/medium.si2", nsGraphics::Vec2D(125,362));
        window << nsShape::Rectangle(nsGraphics::Vec2D(50,450), nsGraphics::Vec2D(400,525), nsGraphics::RGBAcolor(150,150,150));
        window << nsGui::Sprite("../Demineur/assets/hard.si2", nsGraphics::Vec2D(125,462));
        window << nsShape::Rectangle(nsGraphics::Vec2D(50,550), nsGraphics::Vec2D(400,625), nsGraphics::RGBAcolor(150,150,150));
        window << nsGui::Sprite("../Demineur/assets/score.si2", nsGraphics::Vec2D(125,562));
        while (window.getEventManager().hasEvent())
        {
            const nsEvent::Event_t actualEvent = window.getEventManager().pullEvent();
            if (actualEvent.eventType == nsEvent::EventType_t::MouseClick) {
                if (actualEvent.eventData.clickData.x >= 50 && actualEvent.eventData.clickData.x <= 400) {
                    if (actualEvent.eventData.clickData.y >= 250 && actualEvent.eventData.clickData.y <= 325) {
                        whatIsNextPage = "easy";
                    }
                }
            }
        }
        window.finishFrame();
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    //launchGame("medium");
    return 0;
}

void















