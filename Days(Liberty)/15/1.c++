#include <string>
using namespace std;

class Animal {
private:
    string name;

public:
    Animal(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }
};


