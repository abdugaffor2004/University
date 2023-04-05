#include <iostream>
using namespace std;
#include <cmath>

int main() {
    int *arr;
    int n;
    int power;
    cout<<"Enter the size of the array: ";    //Просим пользователя ввести размер массива  
    cin>>n;
    arr = new int[n];

    for(int i=0; i<n ;i++){
        cout<<"Enter the element at index "<<i<<": ";    //Просим пользователя ввести элементы массива 
        cin>>arr[i];
    }

    cout<< "Enter the power: "<< endl;  // Просим пользователя ввести степень 
    cin >> power;
    
    cout<<"Powered array: ";
    for (int i = 0; i < n; i++) {    //Отображаем  новый массив 
        cout << pow(arr[i], power) << " ";
    }
    delete[] arr;    //Освобождение памяти
    return 0;
}