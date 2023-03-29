#include <iostream>
using namespace std;
#include <string>



class autoInfo{

private:

    string _producerName;
    string _modelName;
    int _producedYear;


    void Print(){
        cout << "Producer: " << _producerName << endl;
        cout << "Model: " << _modelName << endl;
        cout << "Year of production: " << _producedYear<< endl;
    }

    public: 

    void setProducerName(string value){
        _producerName = value;
    }

    void setModelName(string value){
        _modelName = value;
    }

    void setProducedYear(int value){
        _producedYear = value;
    }

    string getProducerName(){
        return _producerName;
    };

    string getModelName(){
        return _modelName;
    };

    int getProducedYear(){
        return _producedYear;
    };


    void showDescription(){
        cout << to_string(getProducedYear())<< " " << getProducerName() <<" " << getModelName() <<endl;
    };

    void computeAutoAge(){
        cout << 2023 - getProducedYear() << " years old" << endl;
    }

    void getPrint(){
        showDescription(); Print(); computeAutoAge();
    }
};


int main(){

    autoInfo Impala;

    Impala.setProducerName("Chevrolet");
    Impala.setModelName("Impala");
    Impala.setProducedYear(1957);

    Impala.getPrint();
    
     
};