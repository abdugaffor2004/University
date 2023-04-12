#include <iostream>
using namespace std;


template <class T>

class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


template <class T>
class Tree {
public:
    TreeNode<T>* root; // корневой узел
    Tree() {
        root = nullptr;
    }
    
    void add(T val) {

        TreeNode<T>* newNode = new TreeNode<T>(val);
        if (root == nullptr) {
            root = newNode;
        } // Если корень дерева равен nullptr, то новый узел становится корневым.
        
        else {

            TreeNode<T>* curr = root; //указатель на начало(корень)

            while (curr != nullptr) {
                // Если значение нового узла меньше значения текущего узла, то оно переходит к левому дочернему элементу. 
                if (val < curr->data) {
                    if (curr->left == nullptr) {
                        curr->left = newNode;
                        return;
                    }
                    curr = curr->left;
                } else {
                    if (curr->right == nullptr) {
                        curr->right = newNode;
                        return;
                    }
                    curr = curr->right;
                }

                // Это продолжается до тех пор, пока не будет найден пустой дочерний узел, после чего туда вставляется новый узел.
            }
        }
    }

    TreeNode<T>* del(T val, TreeNode<T>* node) {
        if (node == nullptr) {
            return node;
        }// Если переданный узел равен null, то del просто возвращает null, потому что удалять нечего.

        if (val < node->data) {
            node->left = del(val, node->left);
        } else if (val > node->data) {
            node->right = del(val, node->right);
         } 
        //если значение, подлежащее удалению, меньше значения текущего узла, del рекурсивно вызывается для левого дочернего элемента текущего узла. 
        // Если значение val больше значения текущего узла, del рекурсивно вызывается для правого дочернего элемента.
        
        else {
            if (node->left == nullptr) {
                TreeNode<T>* temp = node->right;
                delete node;
                return temp;
            } // Если у узла есть только один дочерний элемент, мы делаем этот дочерний элемент родительским для узла, подлежащего удалению, тем самым удаляя узел из дерева.
            
            else if (node->right == nullptr) {
                TreeNode<T>* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode<T>* temp = minNode(node->right);
            node->data = temp->data;
            node->right = del(temp->data, node->right);
            // мы находим минимальный узел в правом поддереве и заменяем значение узла, подлежащего удалению, значением минимального узла.
            // Затем мы рекурсивно удаляем минимальный узел из правого поддерева.
        }
        return node;
    }

    void del(T val) {
        root = del(val, root);
    } // рекурсивное удаления узла со значением val из дерева двоичного поиска, имеющего корни в root.

    TreeNode<T>* minNode(TreeNode<T>* node) {
        TreeNode<T>* curr = node;
        while (curr->left != nullptr) { // пока есть левый дочерний элемент, установите узел левым дочерним элементом.
            curr = curr->left;
        }
        return curr;
    }

    void del_subt(TreeNode<T>* node) {
        if (node != nullptr) {
            del_subt(node->left);
            del_subt(node->right);
            delete node;
        }
    } // удаляет все узлы в поддереве с корнем в предоставленном узле.


    TreeNode<T>* printTree(TreeNode<T>* node) {
        if (node) {
            printTree(node->left);
            std::cout << node->data << " ";
            printTree(node->right);
        }
    }
};





int main() {
    // создаем двоичное дерево целых чисел
    Tree<int> intTree;
    intTree.add(5);
    intTree.add(10);
    intTree.add(3);
    intTree.add(7);
    intTree.add(1);
    
    // удалим узел из дерева и выведим оставшиеся элементы по порядку
    intTree.del(10);
    cout << "Int tree after deleting 10: ";
    intTree.printTree(intTree.root);
    cout << endl;
    
    //создаем двоичное дерево строк
    Tree<string> stringTree;
    stringTree.add("apple");
    stringTree.add("banana");
    stringTree.add("cherry");
    
    // удаляем поддерево из дерева и распечатаем оставшиеся элементы порядку
    TreeNode<string>* nodeToDelete = stringTree.root->right;
    stringTree.del_subt(nodeToDelete);
    cout << "String tree after deleting subtree: ";
    stringTree.printTree(stringTree.root);
    cout << endl;
    
    return 0;
}
