#include <iostream>
#include <fstream>
#include <string>
using namespace std;

 int main(int argc, char* argv[]) {

        if (argc < 2) {
            cerr << "Error: no filename provided." << endl;
            return 1;
        }

        string filename = argv[1];
        ifstream file(filename);


        if (!file.is_open()) { 
            cerr << "Error: failed to open file." << endl;
            return 1;
        }

        char c;

        while (file.get(c)) { // считываем каждый символ файла 
            if (isprint(c) || ispunct(c)) {
                cout << c;
            }
        }

        file.close();
        return 0;
    }



