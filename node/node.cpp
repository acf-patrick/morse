#include "node.h"
#include <stack>
#include <string>
#include <iostream>

using namespace std;

// split string
std::vector<std::string> split(std::string str, const std::string& sep) {
    std::vector<std::string> ret;
    size_t pos = 0;
    std::string token;

    while ((pos = str.find(sep)) != std::string::npos) {
        token = str.substr(0, pos);
        ret.push_back(token);
        str.erase(0, pos + sep.length());
    }

    ret.push_back(str);
    // cout << "here : " << str << endl;

    return ret;
}

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei) {
    if (si > ei)
        return -1;
 
    // Inbuilt stack
    stack<char> s;
 
    for (int i = si; i <= ei; i++) {
 
        // if open parenthesis, push it
        if (str[i] == '(')
            s.push(str[i]);
 
        // if close parenthesis
        else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();
 
                // if stack is empty, this is
                // the required index
                if (s.empty())
                    return i;
            }
        }
    }
    // if not found return -1
    return -1;
}
 
// function to construct tree from string
Node* treeFromString(const string& str, int si, int ei) {
    // Base case
    if (si > ei)
        return NULL;
 
    // new root
    Node* root = new Node(str[si]);
    int index = -1;
 
    // if next char is '(' find the index of
    // its complement ')'
    if (si + 1 <= ei && str[si + 1] == '(')
        index = findIndex(str, si + 1, ei);
 
    // if index found
    if (index != -1) {
 
        // call for left subtree
        root->left = treeFromString(str, si + 2, index - 1);
 
        // call for right subtree
        root->right = treeFromString(str, index + 2, ei - 1);
    }
    
    return root;
}

Node::Node(char v) : value(v), left(nullptr), right(nullptr) {}
Node::~Node() {
    if (left)
        delete left;
    if (right)
        delete right;
}
