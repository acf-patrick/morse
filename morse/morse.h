#pragma once

#include <map>
#include <string>
#include "../node/node.h"

class Morse {
    std::map<std::string, char> toString;
    std::map<char, std::string> toMorse;

    std::string decoded;
    Node* tree;

    void retrieve(Node*, const std::string&);

public:
    Morse();

    std::string encode(const std::string&);
    std::string decode(const std::string&);
};