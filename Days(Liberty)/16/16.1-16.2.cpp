#include <iostream>
using namespace std;
#include <string>

int main(){

    // int a;
    // cout << "Initialize var: ";
    // cin >> a; 
    // cout<<  " a = " << a << endl;
    // cerr << " Cerr is done " << endl;
    // clog << " Clog is done " << endl; // 16.1

    char name[80]; // массив символов
    cout << "Enter your full name: ";
    cin.getline(name, 80);
    cout << "Your name: " << name<< endl;

}