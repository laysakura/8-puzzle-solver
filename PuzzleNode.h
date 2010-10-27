#pragma once

#include "Puzzle.h"

class PuzzleNode {
    friend class PuzzleTree;

private:
    Puzzle puz;
    int g;                      // depth
    int f;                      // = g + puz.geth()

public:
    // depth starts from 0
    PuzzleNode(Puzzle puz, int depth);

    int getf() const;
    int geth() const;
};
