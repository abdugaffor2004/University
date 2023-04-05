#include <iostream>
using namespace std;

class Animal{

    friend void setValue(Animal&, int);
    friend void setValue (Animal&, int, int);
    friend void Print( Animal& value);

    private:
        int itsWeight;
        int itsAge;

};

void setValue(Animal& theAnimal, int theWeight){
    theAnimal.itsWeight = theWeight;
}

void setValue(Animal& theAnimal, int theWeight, int theAge){
    theAnimal.itsWeight = theWeight;
    theAnimal.itsAge = theAge;
}

void Print( Animal& value ){
    cout << "Weight: "<< value.itsWeight << endl;
    cout << "Age: " << value.itsAge << endl;

}

int main(){
    Animal peppy;
    setValue(peppy, 2);
    Print(peppy);

    cout << "--------------------------" << endl;

    setValue(peppy, 7, 9);
    Print(peppy);
}