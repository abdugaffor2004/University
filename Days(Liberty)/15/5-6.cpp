#include <iostream>

class Animal{

    private:

        int itsWeight;
        int itsAge;

    public:
        friend void setValue(Animal&, int);
        int getWeight() const{return itsWeight;}
        int getAge() const{return itsAge;}

};

void setValue(Animal& theAnimal, int theWeight){
    theAnimal.itsWeight = theWeight;
}

int main(){
    Animal peppy;

    setValue(peppy, 5)
}