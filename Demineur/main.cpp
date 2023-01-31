#define FPS_LIMIT 60
#include <iostream>
#include <mingl/mingl.h>
#include <thread>
#include "cell.h"
#include "grid.h"
#include "game.h"
#include "draw.h"

using namespace std;

int main()
{
    Grid grid = Grid(5,5,7);
    initGridValue(grid);
    grid.showCells();

    MinGL window("Demineur", nsGraphics::Vec2D(750,750), nsGraphics::Vec2D(100,100), nsGraphics::KGray);
    window.initGlut();
    window.initGraphic();

    chrono::microseconds frameTime = chrono::microseconds::zero();

    while (window.isOpen()) {
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();
        window.clearScreen();

        for (unsigned y = 0; y < grid.getHeight(); ++y) {
            for (unsigned x = 0; x < grid.getWidth(); ++x) {
                drawCell(window, nsGraphics::Vec2D{x*50,y*50}, grid.getCell(x,y));
            }
        }

        window.finishFrame();
        window.getEventManager().clearEvents();
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    return 0;
}
