#include "Puzzle.h"
#include <iostream>
#include <cstdlib>

Puzzle::Puzzle()
{
    // initiate the puzzle
    setNum(4, Point(0, 0));
    setNum(1, Point(1, 0));
    setNum(2, Point(2, 0));
    setNum(6, Point(0, 1));
    setNum(3, Point(1, 1));
    setNum(0, Point(2, 1));
    setNum(7, Point(0, 2));
    setNum(5, Point(1, 2));
    setNum(8, Point(2, 2));

    // setNum(1, Point(0, 0));
    // setNum(2, Point(1, 0));
    // setNum(3, Point(2, 0));
    // setNum(4, Point(0, 1));
    // setNum(5, Point(1, 1));
    // setNum(6, Point(2, 1));
    // setNum(7, Point(0, 2));
    // setNum(8, Point(1, 2));
    // setNum(0, Point(2, 2));

    calch1();
    //calch2();
}

bool Puzzle::swap(Direction dir)
{
    Point p0 = getPoint(0);

    switch (dir) {
    case UP:
        if (p0.y == 0) return false;
        setNum( getNum(Point(p0.x, p0.y - 1)), Point(p0.x, p0.y) );
        setNum( 0, Point(p0.x, p0.y - 1) );
        break;
    case DOWN:
        if (p0.y == 2) return false;
        setNum( getNum(Point(p0.x, p0.y + 1)), Point(p0.x, p0.y) );
        setNum( 0, Point(p0.x, p0.y + 1) );
        break;
    case LEFT:
        if (p0.x == 0) return false;
        setNum( getNum(Point(p0.x - 1, p0.y)), Point(p0.x, p0.y) );
        setNum( 0, Point(p0.x - 1, p0.y) );
        break;
    case RIGHT:
        if (p0.x == 2) return false;
        setNum( getNum(Point(p0.x + 1, p0.y)), Point(p0.x, p0.y) );
        setNum( 0, Point(p0.x + 1, p0.y) );
        break;
    }
    calch1();
    //calch2();
    return true;
}

#ifdef DEBUG
void Puzzle::print()
{
    std::cout << "-- h = " << h << " --" << std::endl;

    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            std::cout << getNum(Point(x, y));
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
#endif

void Puzzle::calch1()
{
    int nexth = 0;
    for (int num = 1; num <= 8; num++) {
        if (getPoint(num) != getRightPoint(num))
            ++nexth;
    }
    h = nexth;
}

void Puzzle::calch2()
{
    int nexth = 0;
    for (int num = 1; num <= 8; num++) {
        Point p = getPoint(num);
        Point rightp = getRightPoint(num);
        nexth += abs(p.x - rightp.x);
        nexth += abs(p.y - rightp.y);
    }
    h = nexth;
}

inline void Puzzle::setNum(int num, Point p)
{
    puz[p.x][p.y] = num;
}

inline int Puzzle::getNum(Point p) const
{
    return puz[p.x][p.y];
}

inline Point Puzzle::getPoint(int num) const
{
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (num == getNum(Point(x, y)))
                return Point(x, y);
    return Point(-1, -1);
}

inline Point Puzzle::getRightPoint(int num) const
{
    return Point( (num - 1) % 3, (num - 1) / 3 );
}
