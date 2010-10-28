#pragma once

#include "Point.h"
#include <string>

enum Direction {
    UP, DOWN, RIGHT, LEFT
};

class Puzzle {
    friend class PuzzleNode;

private:
    int puz[3][3];        // board of 8-puzzle
                               // each 'cell' has 1-8 and 0 (which means null space)
    int h;                     // evaluation function

public:
    // initiate 'puz' and 'h'
    Puzzle(int p[3][3]);
    Puzzle(const std::string& puzSerialized);
    Puzzle(const Puzzle& rhs);

    // swap p and '0'
    // also calculate h
    // returns false if cannot swap
    bool swap(Direction dir);
    // returns this->h
    int geth() const;

    // example:
    // 412
    // 630      =>   "412630758"
    // 758
    std::string serialize();

    // print the current puzzle table & h to stdout
    void print(int g, int f) const;

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
