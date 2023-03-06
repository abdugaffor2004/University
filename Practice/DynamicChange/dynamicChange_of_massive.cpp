
#include <iostream>
using namespace std;

int main(){

    
    int size;

    cout << "Declare size of massive: ";
    cin >> size; 
    cout << endl;

    int *arr = new int[size];

    for(int i=0; i<size; i++){
        arr[i] = rand() % 100;
    };

    for(int i=0; i<size; i++){
        cout << arr[i] << endl;
        cout << arr + i<< endl;
    }

    delete [] arr;

};