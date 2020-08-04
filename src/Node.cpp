#include "../include/Node.h"
#include <iostream>
#include <cmath>
#include <utility>

Node::Node(Node * p, CoordPair c) //: parent(p), coord(std::move(c)), numvisits(0), score(0), leaf(true)
{
    parent = p;
    coord = c;
    numvisits = 0;
    score = 0;
    leaf = true;
    if (p == nullptr)
        distance = 0;
    else {
        distance = get_distance(*p);
        //for (auto & coordinate : p->coordpool) {
        //    if (coordinate != c)
        //        coordpool.emplace_back(coordinate);
        //}
        get_coordpool() = p->coordpool;
    }
}

void Node::print_node() {
    std::cout << coord.first << "," << coord.second << "\n";
}

void Node::add_child(Node * n) {
    children.emplace_back(*n);
}

double Node::get_distance(Node n) {
    double x = coord.first - n.coord.first;
    double y = coord.second - n.coord.second;
    double dist = sqrt(pow(x, 2) + pow(y, 2));
    return dist;
}

void Node::update_score(double new_score) {
    score = score + new_score;
    numvisits = numvisits + 1;
}

std::vector<Node>  Node::get_children()         { return children;  }
double             Node::get_score()            { return score;     }
int                Node::get_numvisits()        { return numvisits; }
bool               Node::is_leaf()              { return leaf;      }
void               Node::set_coord(CoordPair c) { coord = c;        }
Node*              Node::get_parent()           { return parent;   }
bool               Node::has_parent()           { return parent != nullptr; }

std::vector<CoordPair> &Node::get_coordpool() {
    return coordpool;
}


