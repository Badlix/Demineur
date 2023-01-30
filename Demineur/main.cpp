#include <iostream>
#include <mingl/mingl.h>
#include "cell.h"
#include "grid.h"
#include "game.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Grid grid(5,5,7);
    initGridValue(grid);
    grid.showCells();

    MinGL window("Demineur", nsGraphics::Vec2D(750,750), nsGraphics::Vec2D(100,100));

    return 0;
}
