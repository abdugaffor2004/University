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

int main() {
    Node *head = new Node{1, NULL, NULL};
    Node *current = head;
    for (int i = 2; i <= 5; i++) {
        Node* newNode = new Node{i, NULL, current};
        current->next = newNode;
        current = newNode;
    }
    Node* p = head->next; //move second element (value=2) 3 positions forward
    Node* newHead = moveKPositionsForward(p, 3);
    cout << "New list: ";
    for(Node* cur = newHead; cur != NULL; cur = cur->next)
        cout << cur->data << " ";
    cout << endl;
    cout << "First element: " << newHead->data << endl; //prints 1
    //Find last element
    Node* last = newHead;
    while(last->next != NULL)
        last = last->next;
    cout << "Last element: " << last->data << endl; //prints 2
    return 0;
}
