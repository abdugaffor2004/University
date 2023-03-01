#include <iostream>
using namespace std;
#include <string>

class Rocket{
    public:
        int flyHeigth_R = 30; //km

};

class Airplane{
    public:
        int flyHeight_A = 12;

};

class JetPlane : public Rocket, public Airplane{
    public:
        int flyHeight_J = (flyHeigth_R + flyHeight_A)/2;
};



class plane_747 : public JetPlane{
    
};

int main(){

    plane_747 plane_1;


};