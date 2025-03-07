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
    void searchnum(Node*& root,int value){
        if (root== nullptr){
            cout<<"false"<<"\n";
            return;
        }
        if (root->value==value){
            cout<<"true"<<"\n";
            return;
        }
        if (root->value<value){
            searchnum(root->right,value);
        }
        if (root->value>value){
            searchnum(root->left,value);
        }
    }
    void Del(Node*& root,int value){
        if (root==nullptr){
            return;
        }
        if (value<root->value){
            Del(root->left,value);
        }
        else if (value>root->value) {
            Del(root->right, value);
        }
        else{
            if(root->left== nullptr){
                Node* temp=root->right;
                delete root;
                root=temp;
            }
            else if (root->right== nullptr){
                Node* temp=root->left;
                delete root;
                root=temp;
            }
            else{
                Node* temp= minNode(root->right);
                root->value=temp->value;
                Del(root->right,temp->value);
            }
        }
    }
    Node* minNode(Node* node){
        Node* current=node;
        while (current && current->left!= nullptr){
            current=current->left;
        }
        return current;
    }
    int searchPosl(Node* root, int value){
        int result = -1;
        while (root!= nullptr) {
            if (root->value > value) {
                result = root->value;
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return result;

    }
    int searchPred(Node* root, int value){
        int result = -1;
        while (root!= nullptr) {
            if (root->value < value) {
                result = root->value;
                root = root->right;
            } else {
                root = root->left;
            }
        }
        return result;
    }


};
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int num,value;
    Tree l;//создаем обьект l
    Node* root= nullptr; //изначально корень нульптр
    while (cin>>num>>value){
        if (num==0){
            l.insert(root,value);//вызываем функцию insert для добавления
        }
        if (num==1){
            l.Del(root,value);
        }
        if (num==2){
            l.searchnum(root,value);
        }
        if (num==3){
            int next = l.searchPosl(root, value);
            if (next == -1) {
                cout << "none\n";
            }
            else {
                cout << next << "\n";
            }
        }
        if (num==4){
            int prev = l.searchPred(root, value);
            if (prev == -1) {
                cout << "none\n";
            }
            else {
                cout << prev << "\n";
            }
        }
    }
    return 0;
}
