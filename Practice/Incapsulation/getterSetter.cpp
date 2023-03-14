#include <iostream>
#include <string>
using namespace std;

class Student{

private:
    string NAME;
    int AGE;
    string DEPART;
    string GROUP;
    int TERM;

    //  void Print(string name, int age, string depart, string group, int term){
    //     cout << "Name: " << name << endl;
    //     cout << "Age: " << age << endl;
    //     cout << "Department: " << depart << endl;
    //     cout << "Group: " << group << endl;
    //     cout << "Term: " << term << endl << endl;
        
    // };

    void Print(){
        cout << "Name: " << NAME << endl;
        cout << "Age: " << AGE *2 << endl;
        cout << "Department: " << DEPART<< endl;
        cout << "Group: " << GROUP << endl;
        cout << "Term: " << TERM << endl << endl;
    }
    public: 

    // void getPrint(string _name_, int _age_, string _depart_, string _group_, int _term_){
    //     return Print(_name_, _age_, _depart_, _group_, _term_);
    // };

    void setName(string value){
        NAME = value;
    }

    void setAge(int value){
        AGE = value;
    }

    void setDepartment(string value){
        DEPART = value;
    }

    void setGroup(string value){
        GROUP = value;
    }

    void setTerm(int value){
        TERM = value;
    }

    void getPrint(){
        return Print();
    }
};


int main(){

    Student student_1 , student_2;

    // student_1.getPrint("Dilshod", 19, "Medicine", "UVT", 1);
    // student_2.getPrint("Abdugaffor", 18, "ICS", "IVT", 1);

    student_1.setName("Zafar");
    student_1.setAge(18);
    student_1.setDepartment("ICS");
    student_1.setGroup("IVT");
    student_1.setTerm(1);

    student_1.getPrint();

    
     
};