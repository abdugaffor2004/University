
#include <iostream>
#include <cstring>

using namespace std;

class String {
protected:
    char* str;

public:
    String() { };
    String(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    virtual ~String() {
        delete[] str;
    }

    char* getStr() {
        return str;
    }

    void setStr(const char* s) {
        delete[] str;
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    virtual void print() {
        cout << str << endl;
    }
};

class Complex : public String {
private:
    char* real_str;
    char* imag_str;

public:
    Complex() { }

    Complex(const char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);

        char* i_ptr = strstr(str, "i"); // возвращает указатель на первое вхождение в строку, на которую указывает str1, строки, указанной str2 (исключая завершающий нулевой символ).

        if (i_ptr == NULL) {
            cout<< "Invalid input for complex number" << endl;
        }

        int pos = i_ptr - str;

        real_str = new char[pos + 1];
        strncpy(real_str, str, pos);// Следующий фрагмент кода копирует максимум pos символов из строки str в real_str, тем самым гарантируя, что выхода за границы массива не произойдет
        real_str[pos] = 0;

        imag_str = new char[strlen(str) - pos];
        strcpy(imag_str, i_ptr + 1);
    }

    ~Complex() {
        delete[] real_str;
        delete[] imag_str;
    }

    void print() {
        cout << "Real part: " << real_str << ", Imaginary part: " << imag_str << endl;
    }
};

int main() {
    String str("Hello");
    str.print();

    Complex c("2.3+i4.5");
    c.print();

    return 0;
};


