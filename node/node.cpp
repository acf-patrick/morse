#include "node.h"
#include <stack>
#include <string>

using namespace std;

// function to return the index of close parenthesis
int findIndex(string str, int si, int ei)
{
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
Node* treeFromString(const string& str, int si, int ei)
{
    // Base case
    if (si > ei)
        return NULL;
 
    // new root
    Node* root = new Node(str[si] - '0');
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
        root->right
            = treeFromString(str, index + 2, ei - 1);
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
