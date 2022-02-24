#include "morse/morse.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    Morse morse;

    cout << morse.decode(string(argv[1])) << endl;
    
    return 0;
}