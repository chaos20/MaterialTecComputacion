#include <iostream>
#include <winbgim.h>

using namespace std;

int main()
{
    initwindow (600,400);
    setcolor(15);
    setlinestyle(1, 0, 1);
    line(0, 0, 200, 300);
    bar(10, 10, 50, 50);
    getch();
    closegraph();
    return 0;
}
