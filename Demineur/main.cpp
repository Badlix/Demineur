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
//    bool isApplicationRunning (true);
//    Grid grid = Grid(9,9,10);
//    initGridValue(grid);

//    MinGL window("Demineur", nsGraphics::Vec2D(750,750), nsGraphics::Vec2D(100,100), nsGraphics::RGBAcolor(200,200,200));
//    window.initGlut();
//    window.initGraphic();

//    chrono::microseconds frameTime = chrono::microseconds::zero();
//    string page = "menu"; // "menu" - "game" - "gameEnd" - "score"
//    while (window.isOpen()) {

//        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();
//        window.clearScreen();

//        drawGrid(window, grid);
//        events(window, grid);

//        window.finishFrame();
//        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));
//        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
//    }
    launchGame("easy");
    return 0;
}















