#include "../include/Tree.h"
#include <iostream>
#include <utility>

Tree::Tree(Node * n) : root(n), depth(0) {}

void Tree::print_tree() {
    std::queue<Node> q;
    q.emplace(*root);
    while (!q.empty()) {
        Node walker=q.front();
        walker.print_node();
        q.pop();
        for (auto && child: walker.get_children())
            q.emplace(child);
    }
    std::cout<<"end tree\n";
}

Node & Tree::get_root() { return *root; }

