#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Создаем две очереди
    queue<int> q1, q2;
    q1.push(1);
    q1.push(3);
    q1.push(5);

    q2.push(2);
    q2.push(4);
    q2.push(6);

    // Создаем новую очередь, объединив элементы q1 и q2
    queue<int> mergedQueue;
    while (!q1.empty() && !q2.empty()) {
        mergedQueue.push(q1.front());
        q1.pop();
        mergedQueue.push(q2.front());
        q2.pop();
    }
    

    // Выводим указатели на начало и конец полученной очереди 
    cout << "Beginning of merged queue: " << mergedQueue.front() << endl;
    cout << "End of merged queue: " << mergedQueue.back() << endl;

    return 0;
}
