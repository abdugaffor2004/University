#include <iostream>
using namespace std;
void Xtest(int test)
{
    cout << "Inside function Xtest, test =: " << test << "\n";
    if (test) throw test;
}

int main()
{
    cout << "Nachalo\n";
    try // Начало блока try
    {
        cout << "Vnutry bloka try\n";
        Xtest(0); Xtest(1); Xtest(2);
    }

    catch (int i) { // Перехват ошибки
        cout << "Catching an error - value is: "; 
        cout << i << "\n";
    }
}