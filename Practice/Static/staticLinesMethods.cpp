#include <iostream>
using namespace std;


class Apple{

private:
    int _weight;
    string _color;
    static int _Count;

public:

    Apple(){};
     
    Apple(int weight, string color){
        this->_weight = weight;
        this->_color = color;
        _Count++;
    }

    static int getCount(){
        return _Count;
    }




};

int Apple:: _Count = 0; // Initialization of static variable


int main(){

    Apple apple_1(50, "red");
    Apple apple_2(40, "pink");
    Apple apple_3(10, "yellow");
    // Apple apple_4(80, "green");

    cout<< apple_1.getCount() << endl;

    // cout<< apple_1._Count << endl;//Можно и так(при том что _Count в public) 
    // cout << Apple::_Count << endl; // и так

};