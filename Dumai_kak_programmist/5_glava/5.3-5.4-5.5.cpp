#include <iostream>
using namespace std;

class String {
    private:
        char* str;

    public:
        String(const char* s) {  //представляем начальное значение строки, и динамически выделяем память для str, которая инициализируется копией s
            int len = 0;
            while (s[len] != 0) {
                len++;
            }
            str = new char[len + 1];
            for (int i = 0; i < len; i++) {
                str[i] = s[i];
            }
            str[len] = 0;
        }

        void appened(char *array, char nel){            //Метод добавления символа
            char *arrayRecors = new char[array[0] + 1]; 
            int length = array[0] - '0';
            arrayRecors[0] = array[0] + 1;
            for (int i = 1; i < length; i++) {
                arrayRecors[i] = array[i];
            }
            arrayRecors[(int)array[0]] = nel;
            
            for (int i = 0; i < arrayRecors[0]; i++) {
               
                cout<<arrayRecors[i];
            }
        }            //Добавление символа
        
        void concatenate(char *array, char *arrayTwo){  //Метод сцепления строк
            char *arrayRecors = new char[array[0] + arrayTwo[0]]; 
            int length = array[0] - '0';
            int lengthTwo = arrayTwo[0] - '0';
            arrayRecors[0] = array[0] + lengthTwo - 1;
            for (int i = 1; i < length; i++) {
                arrayRecors[i] = array[i];
            }
            for (int i = 1; i < lengthTwo + length; i++) {
                arrayRecors[length + i] = arrayTwo[i];
            }
        
            for (int i = 0; i < length + lengthTwo; i++) {
               
                cout<<arrayRecors[i];
            }
        }  //Сцепление строк

        char* remove(int start, int count) {

        //сначала вычисляем длину строки путем итерации по str до тех пор, пока не достигнет нулевого символа 0, который указывает на конец строки

            int len = 0;
            while (str[len] != 0) {
                len++;
            }
            if (count <= 0 || start < 0 || start >= len) {
                return str;
            }

            char* newStr = new char[len - count + 1]; // выделяет память для нового символьного массива newStr
            for (int i = 0; i < start; i++) {
                newStr[i] = str[i];
            }
            for (int i = start + count; i < len; i++) {
                newStr[i - count] = str[i];
            }
            newStr[len - count] = 0;
            
            return newStr;
        }

        char &operator[](const unsigned nom){
            return str[nom]; 
        }    

        ~String() {
            delete[] str;
        }
};

int main() {
    String myString("example string");

    char* newString = myString.remove(8, 3);
    cout << newString << endl;
    delete[] newString;

   cout<< myString[3] << endl;

    return 0;
}