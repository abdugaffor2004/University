#include <iostream>
#include <string>
using namespace std;

char* substring(const char* arrayString, int startPos, int length) {
    char* newString = new char[length+1];// +1: для нулевого символа-ограничителя 0, который отмечает конец строки.
    int i;
    for (i = 0; i < length; i++) {
        newString[i] = arrayString[startPos + i];
    }
    newString[i] = 0; // нулевой символ
    return newString;
}

void replaceString(string& source, string target, string replaceText) {
    int pos = 0;
    while ((pos = source.find(target, pos)) != string::npos) { // цикл будет продолжаться до тех пор, пока позиция target в source не будет равна string::npo.
        source.replace(pos, target.length(), replaceText); // заменяем target на replaceText
        pos += replaceText.length();
    }
} // 4.3

int main() {
    // const char* str = "abcdefg";

    // char* newStr = substring(str, 3, 4);
    // std::cout << "New string: " << newStr << std::endl;
    // delete[] newStr;

    string source = "abcdabee";
    string target = "ab";
    string replaceText = "xyz";
    replaceString(source, target, replaceText);
    cout << source << endl; //4.3



}