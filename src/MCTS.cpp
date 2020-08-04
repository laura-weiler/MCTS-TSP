
#include "../include/MCTS.h"
#include <cmath>
#include <ctime>
#include <set>
#include <iostream>

/*
 * generate coordpool of TSPsize unique random coordinates
 * TODO: better rng
 */
MCTS::MCTS(Node *n, int size) : Tree(n), TSPsize(size), terminal_state(false) {
    //srand(time(nullptr));
    std::set<int> temp;
    while (temp.size() < size*2) {
        int point = rand()%100;
        temp.emplace(point);
    }
    std::vector<int> coords(temp.begin(), temp.end());
    for (int i=0; i<size*2-1; i=i+2) {
        (*n).coordpool.emplace_back(CoordPair (coords[i],coords[i+1]));
    }
    (*n).set_coord(n->coordpool.front());     // arbitrarily set root coordinate
    (*n).coordpool.erase(n->coordpool.begin()); // remove self from pool
}

//TODO: is this ok?
MCTS::~MCTS()=default;

/*
 * upper confidence bound for the ith child node
 * given by UCB = Vi+2*sqrt(ln(N)/ni) where,
 * Vi is the average value of all the nodes below the current node
 * N is the number of times the parent node has been visited
 * ni is the number of times the child node has been visited
 * auto it = n.get_children().begin();
    for (auto & child: n.get_children()) {}
 */
double MCTS::UCB(Node n, int N) {
    if (n.get_numvisits() == 0)
        return std::numeric_limits<float>::infinity();
    else
        return n.get_score() + 2*sqrt(log(N)/n.get_numvisits());
}

Node* MCTS::select(Node * n) {
    Node * current = n;
    if (current->is_leaf())
        return current;
    double max = 0;
    for (auto & child: current->get_children()) {
        double ucb = UCB(child, current->get_numvisits());
        if (ucb > max) {
            max = ucb;
            current = &child;
        }
    }
    return select(current);
}

void MCTS::expand(Node * n) {
    if (n->coordpool.empty())
        terminal_state = true;
    else {
        for (auto & coord : n->coordpool) {
            Node * child = new Node(n, coord);
            n->add_child(child);
        }
        n->leaf = false;
    }
}

/*
 * call update within simulate
 * this isn't really a random selection
 * TODO: this isn't working !!
 */
void MCTS::simulate(Node * n) {
    double score = 0;
    Node * current = n;
    std::cout<<n->coordpool.size()<<"\n";
    for (auto & coord: n->coordpool ) {
        std::cout << coord.first <<","<<coord.second<< "\n";
        Node temp(current, coord);
        std::cout<<temp.distance<<"\n";
        score = score + 1/temp.distance;
    }
    update(n, score);
}

void MCTS::update(Node * n, double new_score) {
    std::cout<< "score: " << new_score<<"\n";
    Node * current = n;
    current->score = current->score+new_score;
    while (current->has_parent()) {
        current = current->get_parent();
        current->numvisits=current->get_numvisits()+1;
        current->score = current->score+new_score; //also updates num_visits TODO: rename
    }
}

void MCTS::play() {
    expand(root);
    Node * current = select(root);
    for(;;) {
        if (terminal_state) {
            std::cout<<"terminal\n";
            break;
        }
        if (current->is_leaf()) {
            if (current->get_numvisits() == 0) {
                std::cout <<"simulate\n";
                simulate(current);
            }
            else {
                std::cout << "expand\n";
                expand(current);
            }
        } else {
            std::cout << "select\n";
            current = select(current);
        }
    }
}

