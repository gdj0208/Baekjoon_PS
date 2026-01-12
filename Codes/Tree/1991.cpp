//
//  main.cpp
//  Learning
//
//  Created by 구동준 on 2022/10/02.
//

//#include "classtest.hpp"
//#include "DataStructure.h"

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#define null NULL

using namespace std;

class Node {
private:
    char data;
    Node *left, *right, *parent;
public:
    Node(char data, Node *parent, Node *left, Node *right);
    Node *get_left() { return left; }
    Node *get_right() { return right; }
    Node *get_parent() { return parent; }
    char get_data() { return data; }
    
    void set_left(Node* left) { this->left = left; }
    void set_right(Node* right) { this->right = right; }
    void set_parent(Node* parent) { this->parent = parent; }
};

class Alg{
private:
    map<char, Node*> Tree;
    int num_of_leaf;
    
public:
    void run();
    void init_tree();
    void add_leaf(char root, char left, char right);
    void print_for(Node* data);
    void print_mid(Node* data);
    void print_back(Node* data);
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Alg alg;
    alg.run();
}


void Alg::run() {
    
    init_tree();
    print_for(Tree['A']); cout << "\n";
    print_mid(Tree['A']); cout << "\n";
    print_back(Tree['A']); cout << "\n";
}

void Alg::init_tree() {
    cin >> num_of_leaf;
    char root, left, right;
    
    for(int i = 0; i < num_of_leaf; i++) {
        cin >> root >> left >> right;
        add_leaf(root, left, right);
    }
}

void Alg::add_leaf(char root, char left, char right) {
    if(Tree.find(root) == Tree.end()) { Tree[root] = new Node(root, nullptr, nullptr, nullptr); }
    if(left != '.') {
        Tree[root]->set_left( new Node(left, Tree[root], nullptr, nullptr) );
        Tree[left] = Tree[root]->get_left();
    }
    if(right != '.') { 
        Tree[root]->set_right( new Node(right, Tree[root], nullptr, nullptr) );
        Tree[right] = Tree[root]->get_right();
    }
}

Node::Node(char data, Node *parent, Node *left, Node *right) {
    this->data = data;
    this->parent = parent;
    this->left = left;
    this->right = right;
}

void Alg::print_for(Node* node) {
    cout << node->get_data();
    if(node->get_left() != nullptr) { print_for(node->get_left()); }
    if(node->get_right() != nullptr) { print_for(node->get_right()); }
}

void Alg::print_mid(Node* node) {
    if(node->get_left() != nullptr) { print_mid(node->get_left()); }
    cout << node->get_data();
    if(node->get_right() != nullptr) { print_mid(node->get_right()); }
}

void Alg::print_back(Node* node) {
    if(node->get_left() != nullptr) { print_back(node->get_left()); }
    if(node->get_right() != nullptr) { print_back(node->get_right()); }
    cout << node->get_data();
}
