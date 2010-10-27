#include "PuzzleTree.h"
#include <boost/functional/hash.hpp> // for hash table

PuzzleTree::PuzzleTree(int p[3][3])
    : ptree(PuzzleNode(Puzzle(p), 0)),
      htable(HASH_TABLE_SZ, false)
{
    tree<PuzzleNode>::iterator it = ptree.begin();
    registPuzzleToHTable((*it).puz.serialize());
}

void PuzzleTree::genChildren(const tree<PuzzleNode>::iterator& it)
{
    Puzzle pu((*it).puz);
    Puzzle pd((*it).puz);
    Puzzle pl((*it).puz);
    Puzzle pr((*it).puz);
    if (pu.swap(UP) && !alreadyRegistered(pu.serialize())) {
        registPuzzleToHTable(pu.serialize());
        ptree.append_child(it, PuzzleNode(pu, (*it).g + 1));
    }
    if (pd.swap(DOWN) && !alreadyRegistered(pd.serialize())) {
        registPuzzleToHTable(pd.serialize());
        ptree.append_child(it, PuzzleNode(pd, (*it).g + 1));
    }
    if (pl.swap(LEFT) && !alreadyRegistered(pl.serialize())) {
        registPuzzleToHTable(pl.serialize());
        ptree.append_child(it, PuzzleNode(pl, (*it).g + 1));
    }
    if (pr.swap(RIGHT) && !alreadyRegistered(pr.serialize())) {
        registPuzzleToHTable(pr.serialize());
        ptree.append_child(it, PuzzleNode(pr, (*it).g + 1));
    }
}

tree<PuzzleNode>::iterator PuzzleTree::fMinNode() const
{
    int minf = 99999;
    tree<PuzzleNode>::iterator ret;

    tree<PuzzleNode>::leaf_iterator it = ptree.begin_leaf();
    for ( ; it != ptree.end_leaf(); ++it) {
        if ((*it).getf() < minf) {
            minf = (*it).getf();
            ret = it;
        }
    }
    return ret;
}

void PuzzleTree::printTrack(tree<PuzzleNode>::iterator it) const
{
    tree<PuzzleNode>::iterator root = ptree.begin();
    while (it != root) {
        (*it).puz.print();
        it = ptree.parent(it);
    }
    (*it).puz.print();
}

void PuzzleTree::registPuzzleToHTable(const std::string& ps)
{
    boost::hash<std::string> string_hash;
    htable[string_hash(ps) % HASH_TABLE_SZ] = true;
}
bool PuzzleTree::alreadyRegistered(const std::string& ps) const
{
    boost::hash<std::string> string_hash;
    return htable[string_hash(ps) % HASH_TABLE_SZ];
}
