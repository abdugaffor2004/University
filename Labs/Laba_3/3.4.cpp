#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* moveKPositionsForward(Node* p, int k) {
    if(p == NULL) return NULL;
    Node* q = p;
    for (int i = 0; i < k && q != NULL; i++) {
        q = q->next;
    }
    if(q == NULL) return p; //no need to move
    Node* prev = p->prev;
    Node* next = q->next;
    prev->next = p->next;
    next->prev = p;
    p->next = next;
    p->prev = q;
    q->next = p;
    return q == prev ? p : q; //return pointers to first and last element
}

// int main() {
//     Node *head = new Node{1, NULL, NULL};
//     Node *current = head;
//     for (int i = 2; i <= 5; i++) {
//         Node* newNode = new Node{i, NULL, current};
//         current->next = newNode;
//         current = newNode;
//     }
//     Node* p = head->next; //переместить второй элемент (значение=2) на 3 позиции вперед
//     Node* newHead = moveKPositionsForward(p, 3);
//     cout << "New list: ";
//     for(Node* cur = newHead; cur != NULL; cur = cur->next)
//         cout << cur->data << " ";
//     cout << endl;
//     cout << "First element: " << newHead->data << endl;

//     //Находим последний элемент
//     Node* last = newHead;
//     while(last->next != NULL)
//         last = last->next;
//     cout << "Last element: " << last->data << endl; 
    
// }


int main() {

    // создаем связный список
    Node *head = new Node{1, NULL, NULL};
    Node *current = head;
    for (int i = 2; i <= 5; i++) {
        Node* newNode = new Node{i, NULL, current};
        current->next = newNode;
        current = newNode;
    }

    // Выводим первоначальный список
    cout << "Original list: ";
    for(Node* cur = head; cur != NULL; cur = cur->next) {
        cout << cur->data << " ";
    }
    cout << endl;
    
    // переместим на 2 позиции вперед от второго узла
    Node* p = head->next;
    Node* newHead = moveKPositionsForward(p, 2);

    // Выводим новый список
    cout << "New list: ";
    for(Node* cur = newHead; cur != NULL; cur = cur->next) {
        cout << cur->data << " ";
    }
    

    // Первый элемент
    for (Node* cur = newHead; cur != NULL; cur = cur->next)
        cout << endl;
        cout << "First element: " << newHead->data << endl;

    // Находим последний элемент
    Node* last = newHead;
    while(last->next != NULL)
        last = last->next;
    cout << "Last element: " << last->data << endl;

};