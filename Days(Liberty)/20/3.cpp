#include <iostream>
#include <string>
using namespace std;

// Define a new exception derived from the original exception class
class DivideByZeroException : public exception{

public:
    const char* error_message = "Division by zero!";

    const char* what() const throw()
    {
        return error_message;
    }
};


// Выбрасываем новое исключение унаследованное от базового класса исключений
double divide(int a, int b)
{
    if(!b)  // если b == 0
    {
        throw DivideByZeroException();
    }
    if(b > a) 
    {
        throw "The first number is greater than the second one";
    }
    return a / b;
}


void test(int a, int b)
{
    try
    {
        double result = divide(a, b);
        cout << result << endl;
    }
    catch (const DivideByZeroException& e) // объект класса которое обрабатывает исключение
    {
        cout << "Error code: " << e.what() << endl;
    }
    catch (const char* error_message) // Здесь уже простой стороковый литерал
    {
        cout << error_message << endl;
    }
}

int main()
{
    //test(100, 20);      // 5
    test(100, 0);       // Error code: Division by zero
    //test(100, 1000);    // The first number is greater than the second one
}


