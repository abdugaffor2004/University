#include <iostream>
using namespace std;


class Microwave{

    private:

        bool checkVoltage(int &value){
            if(value < 100 && value > 5){
                return true;
            }

            else {return false;};
        };

    public:

        void Start(int parametr)
        {
            bool status = checkVoltage(parametr); // checkVoltage запускается и передает значение переменной
            
            if(status==true){
              cout << "Microwave is ON"<< endl;
            }

            else{cout << "Your input voltage is not appropriate!"<< endl;};

        };

};

int main(){
    Microwave TF_23;

    TF_23.Start(150);
};