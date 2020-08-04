#ifndef MCTS_TSP_TREE_H
#define MCTS_TSP_TREE_H

#include <queue>
#include "Node.h"
using CoordPair = std::pair<int,int>;

class Tree{
    int depth;
public:
    Node * root;
    Tree(Node * n);
    ~Tree()=default;
    void print_tree();
    Node & get_root();
};



#endif //MCTS_TSP_TREE_H
