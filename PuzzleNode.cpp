#include "PuzzleNode.h"

PuzzleNode::PuzzleNode(Puzzle puz, int depth)
    : puz(puz), g(depth)
{
    f = g + puz.geth();
}

int PuzzleNode::getf() const
{
    return f;
}
int PuzzleNode::geth() const
{
    return puz.geth();
}
