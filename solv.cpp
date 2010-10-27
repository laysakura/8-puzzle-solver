#include "Puzzle.h"
#include "PuzzleTree.h"
#include "PuzzleNode.h"
#include "tree.hh"              // this is an STL like library.

int main()
{
    int firstPuzzleBoard[3][3] = {
        {4, 1, 2},
        {6, 3, 0},
        {7, 5, 8}
    };
    PuzzleTree puzTree(firstPuzzleBoard);

    tree<PuzzleNode>::iterator itCur;

    // initiate the puzzle
    Puzzle puz();

    while (true) {
        itCur = puzTree.fMinNode();
        if ((*itCur).geth() == 0) {
            puzTree.printTrack(itCur);
            return 0;
        }
        puzTree.genChildren(itCur);
    }

    return 0;
}
