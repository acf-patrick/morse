#include "morse.h"

using namespace std;

Morse::Morse() {
// Init binderss
    string letters[] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." },
        digits[] = { "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." },
        keys = "abcdefghijklmnopqrstuvwxyz0123456789";

    for (int i=0; i<26+10; ++i) {
        // Numbers
        if (i >= 26) {
            toString[digits[i]] = keys[i];
            toMorse[keys[i]] = digits[i];
        } else {
            toString[letters[i]] = keys[i];
            toMorse[keys[i]] = letters[i];
        }
    }

// Init tree binder
    string strTree = " (e(i(s(h(5)(4))(v( )(3)))(u(f( )( ))( ( )(2))))(a(r(l( )( ))( (+)( )))(w(p( )( ))(j( )(1)))))(t(n(d(b(6)(=))(x(/)( )))(k(c( )( ))(y( )( ))))(m(g(z(7)( ))(q( )( )))(o( (8)( ))( (9)(0)))))";
    tree = treeFromString(strTree, 0, strTree.length()-1);
}

string Morse::encode(const string& str) {
    string ret;
    for (auto car : str) {
        if (car == ' ')
            ret += "/";
        ret += ((car==' ') ? " " : toMorse[car]) + " ";
    }
    return ret;
}

string Morse::decode(const string& morse) {
    if (useBinaryTree)
        retrieve(tree, morse);
    else {
        decoded = "";
        auto words = split(morse, "/");
        for (auto word: words) {
            auto letters = split(word, " ");
            for (auto letter: letters)
                decoded += toString[letter];
            decoded += " ";
        }
    }
    return decoded;
}

void Morse::retrieve(Node* node, const string& morse) {
    if (node == tree)
        decoded = "";
    
    if (node and !morse.empty()) {
        decoded.push_back(node->value);
        auto sub = morse.substr(1);
        auto first = morse[0];
        if (first == '.')
            retrieve(node->left, sub);
        else if (first == '-')
            retrieve(node->right, sub);
        else if (first == ' ')
            decoded.push_back(' ');  
    }
}