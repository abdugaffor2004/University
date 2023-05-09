
#include <iostream>
#include <string>
using namespace std;

class DivideByZeroException : public exception {

public:
    const char* error_message = "Division by zero!";

    const char* what() const throw()
    {
        return error_message;
    }
};

double divide(int a, int b)
{
    if (!b)
    {
        throw DivideByZeroException();
    }
    if (b > a)
    {
        throw "The first number is greater than the second one";
    }
    return a / b;
}

void calculate(int a, int b)
{
    try
    {
        double result = divide(a, b); // 3 уровень
        cout << result << endl;
    }
    catch (const DivideByZeroException& e)
    {
        cout << "Error code: " << e.what() << endl;
    }
    catch (const char* error_message)
    {
        cout << error_message << endl;
    }
}

void test(int a, int b, int c)
{
    calculate(a, b); // 2 уровень
    //calculate(a, c); 
}

int main()
{
    test(100, 20, 5); // 1 уровень
    //test(100, 20, 5);
}
