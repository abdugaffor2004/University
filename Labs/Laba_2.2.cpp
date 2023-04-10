#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Определяем две очереди для хранения значений
    queue <int> firstQ;
    queue <int> secondQ;

    int P1, P2, P3, P4;
    // cin >> P1 >> P2 >> P3 >> P4;

    P1 = 1;
    P2 = 10;
    P3 = 3;
    P4 = 5;

    // Заполняем первую очередь значениями от P1 до P2
    for (int i = P1; i <= P2; i++) {
        firstQ.push(i);
    }

    for (int i = P3; i <= P4; i++) {
        secondQ.push(i);
    }

    // Перемещаем элементы из первой очереди во вторую очередь до тех пор, пока передний элемент в первой очереди не станет четным   
    while (!firstQ.empty() && firstQ.front() % 2 != 0) {
        int val = firstQ.front();
        secondQ.push(val);
        firstQ.pop();
    }


    
    if (!firstQ.empty()) {
        cout << firstQ.front() << " " << firstQ.back() << endl;
    } else {
        cout << "NULL" << " " << "NULL" << endl;
    }

    if (!secondQ.empty()) {
        cout << secondQ.front() << " " << secondQ.back() << endl;
    } else {
        cout << "NULL" << " " << "NULL" << endl;
    }

    
}


/* The first queue will contain the values 2-10, while the second queue will contain the values 1-3.
The while loop that moves elements from the first queue to the second queue checks if the front element of the first queue is even with the condition firstQ.front() % 2 != 0.
If the front element is odd, it will continue to move elements to the second queue until an even element is found.*/