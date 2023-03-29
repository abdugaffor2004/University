

#include <iostream>
using namespace std;

class Apple{

private:
    string _color;
    static int _Count;

public:
     
    Apple(string color){
        this->_color = color;
        _Count++;
    }


    void showColor(){
        cout << "Color: " << _color << endl;
    };

    void ShowCount(){
        cout << "Count: "<< _Count << endl;
        cout << "-------------------" << endl;
    };

    static int getCount(){
        return _Count;
    }

    

    ~Apple(){
        _Count--;
        cout << "Destructor is working: " << _Count << endl;
    }

};

int Apple:: _Count = 0; // Инициализация Статической переменной


int main(){

    // Apple apple_1("red"); // Для 2 и 3
    //     apple_1.showColor();
    //     apple_1.ShowCount();

    // Apple apple_2("pink");
    //     apple_2.showColor();
    //     apple_2.ShowCount();

    // Apple apple_3("yellow");
    //     apple_3.showColor();
    //     apple_3.ShowCount();

    // cout << Apple::getCount() << endl;


// ----------------------------------------------


    void (Apple:: *showColor_p)(); // Указатель на функцию (4 задание)

    showColor_p = Apple::showColor;

    Apple apple_4("black"); 
    (apple_4.*showColor_p)();
    cout << Apple::getCount() << endl;


};