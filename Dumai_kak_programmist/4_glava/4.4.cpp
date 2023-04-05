
#include <iostream>
#include <cstring>
using namespace std;

void resize(char*& data, int new_size) {
    char* new_data = new char[new_size];
    int len = data[0]; // длинна массива
    memcpy(new_data, data, min(new_size, len + 1)); // копируем количество символов из старого массива в новый массив
    delete[] data;
    data = new_data; // Обновляем указатель
}

void append(char*& data, char c) { // указатель на массив, и символ для добавления в конец массива
    int old_len = data[0]; // текущая длинна массива
    resize(data, old_len + 2); // изменяем на old_len+2(учитывая нулевой и новый символы)
    data[++old_len] = c; // добавляем новый символ в массив
    data[0] = old_len; //Обновляем длинну массива сохр. в первом элем. массива
}

void concatenate(char*& data, char* str) {
    int old_len = data[0];
    int str_len = strlen(str);
    resize(data, old_len + str_len + 1);
    memcpy(data + old_len + 1, str, str_len);
    data[0] += str_len; //Обновляем длинну массива сохр. в первом элем. массива
}

char charAt(const char* data, int index) {
    int len = data[0]; 
    if (index < 0 || index >= len) {
        return 0;
    }
    return data[index + 1]; // возвращает символ с указанным индексом в строке
}

void output(const char* data) {
    int len = data[0];
    for (int i = 1; i <= len; i++) {
        cout << data[i];
    }

    cout<< endl << "String size: " << len << endl;
}

int main() {
    char* s = new char[1];
    s[0] = 0;

    append(s, 'H');
    append(s, 'e');
    append(s, 'l');
    append(s, 'l');
    append(s, 'o');
    concatenate(s, " World!");
    output(s);  

    delete[] s;

    return 0;
}
