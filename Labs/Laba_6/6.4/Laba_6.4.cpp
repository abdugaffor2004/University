
#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

void MakeTrain() {
    deque<int> train; // Двухсторонняя Очередь

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        string command;
        iss >> command;

        if (command == "+left") {
            int wagon;
            iss >> wagon;
            train.push_front(wagon);
        }
        else if (command == "+right") {
            int wagon;
            iss >> wagon;
            train.push_back(wagon);
        }
        else if (command == "-left") {
            int n;
            iss >> n;

            for (int i = 0; i < n && !train.empty(); i++) {
                train.pop_front();
            }
        }
        else if (command == "-right") {
            int n;
            iss >> n;

            for (int i = 0; i < n && !train.empty(); i++) {
                train.pop_back();
            }
        }

        if (train.empty()) {
            continue;
        }


        if(command == ""){

            for (auto it = train.begin(); it != train.end(); it++) {
            cout << *it << " ";
        }
            break;
        }
        
    }
}


int main(){

    MakeTrain();

};