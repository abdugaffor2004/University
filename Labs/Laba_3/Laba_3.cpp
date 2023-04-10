#include <iostream>
#include <string>
using namespace std;

class Student {

protected:
    string full_name;
    char gender;
    int age;

public:
    Student(string f, char g, int a) : full_name(f), gender(g), age(a) {}
    virtual ~Student() {}

    virtual string get_full_name() {
        return full_name;
    }

    virtual char get_gender() {
        return gender;
    }

    virtual int get_age() {
        return age;
    }
  
    virtual void display() {
        cout << "\nFull name: " << full_name << "\nGender: " << gender << "\nAge: " << age << endl;
    }
};

class SchoolStudent : public Student {

private:
    int class_number;
    char class_letter;
    
public:
    SchoolStudent(string f, char g, int a, int cn, char cl) : Student(f, g, a), class_number(cn), class_letter(cl) {}
  
    virtual int get_class_number() {
        return class_number;
    }
  
    virtual char get_class_letter() {
        return class_letter;
    }
  
    virtual void display() {
        cout<< "\n<<School student>>" << "\nFull name: " << full_name << "\nGender: " << gender << "\nAge: " << age
             << "\nClass: " << class_number << class_letter << endl;
    }
};

class CollegeStudent : public Student {
private:
    string faculty;
    string specialty;
    int group_number;
public:
    CollegeStudent(string f, char g, int a, string fa, string sp, int gn) : Student(f, g, a), faculty(fa), specialty(sp), group_number(gn) {}

    virtual string get_faculty() {
        return faculty;
    }

    virtual string get_specialty() {
        return specialty;
    }

    virtual int get_group_number() {
        return group_number;
    }

    virtual void display() {
        cout<< "\n<<Collage student>>" << "\nFull name: " << full_name << "\nGender: " << gender << "\nAge: " << age 
             << "\nFaculty: " << faculty << "\nSpecialty: " << specialty << "\nGroup: " << group_number << endl;
    }
};

class PostgraduateStudent : public Student {
private:
    string research_title;
    string advisor;
public:
    PostgraduateStudent(string f, char g, int a, string rt, string adv) : Student(f, g, a), research_title(rt), advisor(adv) {}

    virtual string get_research_title() {
        return research_title;
    }

    virtual string get_advisor() {
        return advisor;
    }

    virtual void display() {
        cout<< "\n<<Postgraduate student>>" << "\nFull name: " << full_name << "\nGender: " << gender << "\nAge: " << age 
             << "\nResearch Title: " << research_title << "\nAdvisor: " << advisor << endl;
    }
};



int main(){

    // Student S_1("Lutfillaev A.S.", 'M', 18);
    // S_1.display();
    // -------------------------------------------------------------------------

    SchoolStudent S_2("Lutfillaev A.S.", 'M', 18, 11, 'A');
    S_2.display();
    // -------------------------------------------------------------------------

    CollegeStudent S_3("Lutfillaev A.S.", 'M', 18, "Computer Science", "Software engineer", 1);
    S_3.display();
    //--------------------------------------------------------------------------

    PostgraduateStudent S_4("Lutfillaev A.S.", 'M', 18, "Cloud techologies", "Mr. John");
    S_4.display();

}