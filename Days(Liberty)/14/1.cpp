
#include <iostream>
using namespace std;

class Apple{

private:
    string _color;
    static int _Count;

public:

    Apple(){};
     
    Apple(string color){
        this->_color = color;
        _Count++;
    }

    static int getCount(){
        return _Count;
    }


    ~Apple(){
        _Count--;
    }

};

int Apple:: _Count = 0; // Инициализация Статической переменной


int main(){

    Apple apple_1("red");
    Apple apple_2("pink");
    Apple apple_3("yellow");

    cout<< apple_1.getCount() << endl;

    // cout<< apple_1._Count << endl;//Можно и так(при том что _Count в public) 
    // cout << Apple::_Count << endl; // и так

};