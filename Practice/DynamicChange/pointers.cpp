#include <iostream>
using namespace std;

void easyPointers(){
    
   int a = 42;

   int *pa = &a;

   cout << "a: " << a << endl;
   cout << "pa: " << pa << endl;
   cout << "*pa: " << *pa << endl;

   *pa = 5;     

   cout << "*pa: " << *pa << endl;

};

void arrayPointer(){
    int size = 10;
    int *arr = new int[size]; // 

    for(int i=0; i<size; i++){
        cout << *(arr + i) << endl;
    }
};


int main(){

    arrayPointer();

};