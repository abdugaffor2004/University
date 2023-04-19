#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
public:
    Student();
    Student(const string& name, const int age);
    Student(const Student& rhs);
    ~Student();

    void  SetName(const string& name);
    string GetName() const;
    void  SetAge(const int age);
    int GetAge() const;

    Student& operator=(const Student& rhs);

private:
    string itsName;
    int itsAge;

};

Student::Student():itsName("New Student"), itsAge(16) {}

Student: : Student(const string& name, const int age)
    : itsName(name), itsAge(age) {}

Student: : Student(const Student& rhs)
    : itsName(rhs.GetName()), itsAge(rhs.GetAge()) {}

Student::~Student() {};


void Student::SetName(const string& name) {
    itsName = name;
};

string Student::GetName() const {
    return itsName;
}

void Student::SetAge(const int age) {
    itsAge = age;
}

int Student::GetAge() const {
    return itsAge;
}

Student& Student::operator=(const Student& rhs){
    itsName = chs.GetName();
    itsAge = rhs.GetAge();
}

ostream& operator<<(ostream& os, const Student& rhs)
{
    os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
    return os;
}

template<class T>
void ShowVector(const vector<T>& v);

typedef vector<Student> SchoolClass;


int main(){


    
}