#pragma once

#include "Point.h"

enum Direction {
    UP, DOWN, RIGHT, LEFT
};

class Puzzle {
private:
    int puz[3][3];        // board of 8-puzzle
                               // each 'cell' has 1-8 and 0 (which means null space)
    int h;                     // evaluation function

public:
    // initiate 'puz' and 'h'
    Puzzle();

    // swap p and '0'
    // also calculate h
    // returns false if cannot swap
    bool swap(Direction dir);

#ifdef DEBUG
    // print the current puzzle table & h to stdout
    void print();
#endif

private:
    // calculate h of current puzTable
    void calch1();
    void calch2();

    // set 'num' to 'p'
    void setNum(int num, Point p);
    // get number on 'p'
    int getNum(Point p) const;
    // get position of 'num'
    Point getPoint(int num) const;
    // get right position of 'num'.
    // ex) (1, 2) for '6'
    Point getRightPoint(int num) const;
};
