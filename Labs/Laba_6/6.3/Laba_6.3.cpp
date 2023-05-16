
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    // Назначение переменных
    string word;
    set<char> word1_letters;
    set<char> word2_letters;

    // Пройдемся по каждому слову 
    for (int i = 0; i < 2; i++) {
        cin >> word;

        // добавим в первое множество все уникальные буквы из первого слова
        if (i == 0) {
            for (char letter : word) {
                word1_letters.insert(letter);
            }
        }
        
        else {
            
            for (char letter : word) { // добавим во второе множество все уникальные буквы из второго слова
                word2_letters.insert(letter);
            }

            for (char letter : word1_letters) { 
                if (word2_letters.count(letter) == 0) { // Проверяем наличие букв из первого множества во втором множестве
                    word1_letters.erase(letter); // Если совпадения букв нет, то удаляем букву
                }
            }
        }
    }

    // выводим результат в алфавитном порядке
    for (char letter : word1_letters) {
        cout << letter;
    }
    cout << endl;

    return 0;
}
