#include <iostream>
using namespace std;



class divisionByZero { // производный класс для обработки исключений связанных с делением на ноль
        public:
            string error_message = "Division by zero!";

            divisionByZero();
            ~divisionByZero();

            void printError(){
                cout << error_message << endl;
            }
    };


 class decimalForm {
        public:
            decimalForm();
            ~decimalForm();

            const char* error_message = "The first number is greater than the second one";

            void printError(){
                cout << error_message << endl;
            }

    };




 double divide(int a, int b)
    {
        if(!b)  // если b == 0
        {
            
            throw divisionByZero::printError();
        }
        if(b > a) 
        {
            throw decimalForm::printError();
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
    
    catch(divisionByZero& theException1){
        theException1.printError();
    }

    catch(decimalForm& theException2){
        theException2.printError();
    }
}



  
int main()
{
   // test(100, 20);      // 5
     test(100, 0);       // Error code: Division by zero
    // test(100, 1000);    // The first number is greater than the second one
}

// ERROR