#include <iostream>
#include "cell.h"
#include "grid.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    Grid grid(2,2,0);
    grid.showCells();
    //grid.getCell(0,0).value += 3;
    cout << grid.getLeftCell(grid.getCell(1,0)).value << endl;
    return 0;
}
