#pragma once

#include "PuzzleNode.h"
#include "tree.hh"

class PuzzleTree {
private:
    // must be greater than the total number of all PuzzleNode
    static const std::size_t HASH_TABLE_SZ = 10000;

private:
    tree<PuzzleNode> ptree;

    // index is boost::hash<std::string>
    // where string is unique puzzle board like
    // 412
    // 630      =>   "412630758"
    // 758
    // So, if (htable[string_hash("412630758")] == true) ,
    // then this puzzle already exists
    std::vector<bool> htable;

public:
    PuzzleTree(int p[3][3]);
    PuzzleTree(const std::string& puzSerialized);

    // never create the same puzzle.
    // uses Puzzle hash table like:
    void genChildren(const tree<PuzzleNode>::iterator& it);
    // uses leaf_iterator
    tree<PuzzleNode>::iterator fMinNode() const;
    // just track parents
    void printTrack(tree<PuzzleNode>::iterator it) const;

private:
    void registPuzzleToHTable(const std::string& ps);
    bool alreadyRegistered(const std::string& ps) const;
};
