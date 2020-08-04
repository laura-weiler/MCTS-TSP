
#include "include/Node.h"
#include "include/MCTS.h"
#include <iostream>

int main() {
    Node * root = new Node();
    auto * tsp = new MCTS(root, 10);
    tsp->expand(root);
    Node * temp = tsp->select(root);
    std::cout<<(*temp).coordpool.size() <<"\n";
    //tsp->play();
    return 0;
}
