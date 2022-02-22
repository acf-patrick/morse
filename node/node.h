#pragma once

#include <string>
#include <vector>

class Node {
public:
    Node(char v = ' ');
    ~Node();

    Node *left, *right;
    char value;
};

std::vector<std::string> split(std::string, const std::string&);
Node* treeFromString(const std::string&, int, int);