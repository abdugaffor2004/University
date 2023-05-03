#include <iostream>
using namespace std;



 double divide(int a, int b)
    {
        if(!b)  // если b == 0
        {
            string error_message = "Division by zero!";
            throw error_message;
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
    catch (string error_message)
    {
        cout << "Error code: " << error_message << endl;
    }
    catch (const char* error_message)
    {
        cout << error_message << endl;
    }
}
  
int main()
{
   // test(100, 20);      // 5
     test(100, 0);       // Error code: Division by zero
    // test(100, 1000);    // The first number is greater than the second one
}