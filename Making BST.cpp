#include <iostream>
using namespace std;
struct Node{
    Node* right;
    Node* left;
    int value;
    Node(int v,Node* l, Node* r){
        value =v;
        left= l;
        right= r;
    }

};
class Tree{
public:
    Node* makeNoda(int value){
        Node* newNode= new Node(value, nullptr, nullptr);
        return newNode;
    }
    void insert(Node*& root,int value) {
        if (root == nullptr) {//условия выхода из рекурсии что если корень равен nullptr то создаем новый узел
            root = makeNoda(value);
            return;
        }// если корень не равен нульптр
        if (value < root->value) {// если значение текущего элемента меньше корня, то , 
            insert(root->left, value);//то текущий элемент будет левым поддеревом
        } 
        if (value > root->value) {
            insert(root->right, value);//иначе правым
        }
    }
    void printNode(Node* root){
        if (root== nullptr) {//если корень нульптр то выходим
            return;
        }
        printNode(root->left);//рекурсивно выводим левый,  затем правый (до правого выведен root)
        cout<<root->value<<" ";
        printNode(root->right);

    }


};
int main() {
    int count,num;
    cin>>count;
    Tree l;//создаем обьект l
    Node* root= nullptr; //изначально корень нульптр
    for (int i=0;i<count;i++){
        cin>>num;
        l.insert(root,num);//вызываем функцию insert для добавления
    }
    l.printNode(root);//вызываем функцию printNode для вывода
    return 0;
}
