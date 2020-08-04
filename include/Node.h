#ifndef MCTS_TSP_NODE_H
#define MCTS_TSP_NODE_H

#include <vector>
using CoordPair = std::pair<int,int>;

class Node {
    std::vector<Node> children;
    Node * parent;
public:
    int numvisits;
    double score;
    bool leaf;       //TODO: make private with setter
    double distance; //TODO: make private with setter
    std::vector<CoordPair> coordpool; //TODO: make private with setter and getter
    CoordPair coord;
    Node(Node * p, CoordPair c);
    Node()=default;
    std::vector<Node> get_children();
    double get_score();
    int get_numvisits();
    bool is_leaf();
    void print_node();
    void add_child(Node* n);
    void set_coord(CoordPair c);
    double get_distance(Node n);
    std::vector<CoordPair>& get_coordpool();
    Node * get_parent();
    bool has_parent();
    void update_score(double new_score);
};


#endif //MCTS_TSP_NODE_H
