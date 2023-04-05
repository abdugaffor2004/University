
#include <iostream>
using namespace std;
struct Node { // Связный список

    int studNum, grage;
    Node *next; // указатель на следующий узел в списке
    
};

class List {

    private:

        Node *head; // указатель на первый узел в списке

    public:

        List() 
        {
            head = NULL; 
        }
        
        void addNode(int num, int grage) // создает новый узел, присваивает входные значения элементам узла studNum и studentsGrade и добавляет узел в конец списка.
        {
            Node *node = new Node; 
            
            node->studNum = num;
            node->grage = grage;
            node->next = NULL;  

    //Когда в список добавляется новый узел, head используется для обхода списка и поиска последнего узла, чтобы новый узел можно было добавить в конце.
        
            if(head == NULL)     
                head = node;
            else                 
            {
                Node *current = head;
                
                while(current->next != NULL)
                    current = current->next;
                
                current->next = node;
            }
        }
        
        void printList() // Выводит информацию о всех студентах
        {
            Node *current = head;
            while(current != NULL)
            {
                cout << "Student nomber: " << current->studNum << endl << "Student grage: " << current->grage << endl << endl;
                current = current->next;
            }
        }
        
        void printStudInRangeOf(int min, int max) //Выводит информацию в выбранном диапозоне
        {
            Node *current = head;
            while(current != NULL)
            {
                if(current->grage >= min  && current->grage <= max)
                {
                    cout << "Student nomber: " << current->studNum << endl << "Student grage: " << current->grage << endl << endl;
                    
                }
                current = current->next;
            }
        }
};
int main()
{
    List myList;
    myList.addNode(5, 70);
    myList.addNode(11, 40);
    myList.addNode(112, 60);
    myList.addNode(141, 90);
    myList.addNode(12, 80);
    
    //myList.printList();           //Выводит информацию о всех студентах

    

    myList.printStudInRangeOf(70, 100);   //Выводит информацию в выбранном диапозоне
    return 0;
}


