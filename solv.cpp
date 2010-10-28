#include "Puzzle.h"
#include "PuzzleTree.h"
#include "PuzzleNode.h"
#include "tree.hh"              // this is an STL like library.
#include <iostream>

bool checkArg(const std::string& arg)
{
    if (arg.length() != 9) return false;

    std::string checkStr("xxxxxxxxx");

    for (int i = 0; i < 9; i++)
        checkStr[ arg[i] - '0' ] = 'o';

    return checkStr == std::string("ooooooooo");
}

void errExit(const std::string& argv0)
{
    std::cerr << "Wrong type argument." << std::endl
              << "Usage:" << std::endl
              << "\t$ " << argv0 << " SERIALIZED_PUZZLE" << std::endl
              << std::endl
              << "'SERIALIZED_PUZZLE' is like:" << std::endl
              << std::endl
              << "\t412" << std::endl
              << "\t630" << "\t=>\t" << "412630758" << std::endl
              << "\t758" << std::endl
              << std::endl;
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 2) errExit(argv[0]);

    std::string puzSerialized(argv[1]);
    if (!checkArg(puzSerialized)) errExit(argv[0]);

    PuzzleTree puzTree(puzSerialized);

    tree<PuzzleNode>::iterator itCur;

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
