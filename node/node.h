#pragma once

#include <string>

class Node {
public:
    Node(char v = ' ');
    ~Node();

    Node *left, *right;
    char value;
};

Node* treeFromString(const std::string&, int, int);