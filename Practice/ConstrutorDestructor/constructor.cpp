#include <iostream>
using namespace std;
#include <math.h>


class Power{

private:
    int number;
    float i;

    float rooting(){
        return pow(number, i); 
    };

public:

    Power(int valueNumber, float valueI){
        number = valueNumber;
        i = valueI;
    };


    void Print(){

        cout << rooting() << endl;

    };
    

};

int main(){

    int num;
    float power;

    cout << "Type a number and power of root: ";
    cin >> num >> power;

    Power proto_1(num, power);
    proto_1.Print();


};