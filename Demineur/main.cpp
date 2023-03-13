#define FPS_LIMIT 60
#include <iostream>
#include <mingl/mingl.h>
#include <thread>
#include "mingl/shape/rectangle.h"
#include "mingl/gui/text.h"
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

    MinGL window("Demineur", nsGraphics::Vec2D(450,750), nsGraphics::Vec2D(550,100), nsGraphics::RGBAcolor(200,200,200));
    window.initGlut();
    window.initGraphic();

    chrono::microseconds frameTime = chrono::microseconds::zero();
    string page = "menu"; // "menu" - "game" - "gameEnd" - "score"
    while (window.isOpen()) {
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        window << nsShape::Rectangle(nsGraphics::Vec2D(50,250), nsGraphics::Vec2D(400,325), nsGraphics::RGBAcolor(175,175,175));
        window << nsGui::Text(nsGraphics::Vec2D(10,22), std::to_string(cell.value), whichNumberColor(cell.value), nsGui::GlutFont::BITMAP_HELVETICA_18);
        window << nsShape::Rectangle(nsGraphics::Vec2D(50,350), nsGraphics::Vec2D(400,425), nsGraphics::RGBAcolor(175,175,175));
        window << nsShape::Rectangle(nsGraphics::Vec2D(50,450), nsGraphics::Vec2D(400,525), nsGraphics::RGBAcolor(175,175,175));
        window << nsShape::Rectangle(nsGraphics::Vec2D(50,550), nsGraphics::Vec2D(400,625), nsGraphics::RGBAcolor(175,175,175));
        window.finishFrame();
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    //launchGame("medium");
    return 0;
}















