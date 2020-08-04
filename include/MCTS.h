
#ifndef MCTS_TSP_MCTS_H
#define MCTS_TSP_MCTS_H

#include <map>
#include "Tree.h"
using CoordPair = std::pair<int,int>;

class MCTS: public Tree {
    int TSPsize;
    bool terminal_state;
    static double UCB(Node n, int N);
    static void update(Node * n, double new_score);
public:
    MCTS(Node *n, int size);
    ~MCTS();
    void play();
    static Node* select(Node * n);
    void expand(Node * n);
    void simulate(Node * n);
};


#endif //MCTS_TSP_MCTS_H
