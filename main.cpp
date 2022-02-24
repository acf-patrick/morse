#include "morse/morse.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    Morse morse;

    int choice = -1;
    while (choice) {
        cout << "\n===== Morse decoder =====" << endl;
        cout    << "1. Decode" << endl
                << "2. Encode" << endl
                << "0. Quit" << endl;
        cout << "Input choice : "; cin >> choice;
        string input;
        if (choice == 1) {
            cout << "Example :" << endl;
            cout << "....;.;.-..;---/.--;---;.-.;.-..;-.. is Hello World\n";
            cout << "Enter Morse code : "; cin >> input;
            cout << "> " << morse.decode(input) << endl;
        } else if (choice == 2) {
            cout << "Your string : "; cin >> input;
            cout << "> " << morse.encode(input) << endl;
        }
    }
    
    return 0;
}