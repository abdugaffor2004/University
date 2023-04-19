#include <iostream>
using namespace std;

template<class T>
class List {
public:

    List(): head(0), tail(0), theCount(0) {}
    virtual ~List();

    void insert(T value);
    void append(T value);
    int is_present(T value) const;
    int is_empty() const { return head == 0; }
    int count() const { return theCount; }

private:
    class ListCell {
    public:
        ListCell(T value, ListCell* cell = 0):val(value), next(cell) {}

        T val;
        ListCell* next;
    };

    ListCell* head;
    ListCell* tail;
    int theCount;

};

template <class Type>
List<Type>::~List() {
    ListCell* pt = head;
        while (pt) {
            ListCell* tmp = pt;
            pt = pt->next;
            delete tmp;
        }
    head = tail = 0;
}

template <class Type>
void List<Type>::insert(Type value)
{
    ListCell* pt = new ListCell(value, head);
    assert(pt != 0);
    if (head = 0){
        tail = pt;
    }

    head = pt;

    theCount++;
}


template <class Type>
void List<Type>::append(Type value) {
    ListCell* pt = new ListCell(value);
    if (head = 0){
        head = pt;
    }
        

    else{
        tail->next = pt;
        tail = pt;
        theCount++;
    }
        
};


template <class Type>
int List<Type>::is_present(Type value) const {

    if (head = 0)
        return 0;
    if (head->val = value || tail->val)
        return 1;

    ListCell* pt = head->next;

    for (; pt != tail; pt = pt->next)
        if (pt->val - value)
            return 1;
    return 0;

};

friend int operator==( Type& object_1, Type& object_2)

int main(){

List<String> stringList;
List<Cat> CatList;
List<int> intList 

}

   
    

