#include <iostream>
using namespace std;
struct Node{
    Node* right;
    Node* left;
    int value;
    int size;
    Node(int v,Node* l, Node* r,int s){
        value =v;
        left= l;
        right= r;
        size=s;
    }

};
Node* makeNoda(int value){
        Node* newNode= new Node(value, nullptr, nullptr,1);
        return newNode;
    }
    void sizeup(Node* root){
        int size_l=0;
        int size_r=0;
        if (root->left!= nullptr){
            size_l=root->left->size;
        }
        if (root->right!= nullptr){
            size_r=root->right->size;
        }
        root->size=size_r+size_l+1;
    };
    Node* insert(Node* root,int value) {
        if (root == nullptr) {//условия выхода из рекурсии что если корень равен nullptr то создаем новый узел
            return makeNoda(value);
        }
        if (value < root->value) {// если значение текущего элемента меньше корня, то ,
            root->left=insert(root->left, value);//то текущий элемент будет левым поддеревом
        }
        else {
            root->right=insert(root->right, value);//иначе правым
        }
        sizeup(root);
        return root;
    }
Node* Del(Node* root, int data) {
    if ( root == nullptr ) {
        return nullptr;
    }
    if (data < root->value) {
        root->left = Del(root->left, data);
    } else if (data > root->value) {
        root->right = Del(root->right, data);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        root->value = temp->value;
        root->right = Del(root->right, temp->value);
    }
    sizeup(root);
    return root;
}
    int search_max(Node* root, int k){
        int size_r=root->right ? root->right->size : 0;
        if (k<=size_r){
            return search_max(root->right,k);
        }
        else if (k==size_r+1){
            return root->value;
        }
        else{
            return search_max(root->left,k-size_r-1);
        }
    };
int main() {
    int num;
    cin>>num;
    Node* root= nullptr; //изначально корень нульптр
    int chislo,k;
    while (num>0){
        num--;
        cin>>chislo>>k;
        if (chislo==1){
            root=insert(root,k);
        }
        if (chislo==0){
            cout<<search_max(root,k)<<endl;
        }
        if (chislo==-1){
            root=Del(root,k);
        }
    }
    return 0;
}
