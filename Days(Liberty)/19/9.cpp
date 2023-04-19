#include <iostream>
using namespace std;

template<class T>
void Transfer( T value_1, T value_2 ){

    cout << endl;
    cout << "/Before/ "<< endl << "value_1: " << value_1 << endl << "value_2: " << value_2<< endl;

    T temprorary = value_1;
    value_1 = value_2;
    value_2 = temprorary;

    cout << endl;
    cout << "/After/ "<< endl << "value_1: " << value_1 << endl << "value_2: " << value_2<< endl;

}

int main(){

    Transfer( 12, 15 );

}