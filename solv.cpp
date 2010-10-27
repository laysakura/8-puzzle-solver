#include "Puzzle.h"

int main()
{
    Puzzle puz;

    puz.print();
    puz.swap(LEFT);
    puz.swap(UP);
    puz.swap(RIGHT);
    puz.print();
    return 0;
}
