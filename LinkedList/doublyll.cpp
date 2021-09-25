#include <iostream>
using namespace std;

template <class T> class Node{
    public :
        int data;
        Node<T> *next;
        Node<T> *prev;
        Node(T value) {
            data = value;
        }
        
        void display(){
            if(this == NULL){
                cout << "NULL\n";
                return;
            }
            cout << this->data << "->";
            this->next->display();
        }
        void insertNext(T value){
            if(this == NULL){
                this = new Node<T>(value);
            }
            if(this->next == NULL){
                this->next = new Node<T>(value);
                return;
            }
            this->next->insertNext(value);
        }
};

int main(){
    Node<int> *head = new Node<int>(0);
    head->insertNext(1);
    head->display();
    return 0;
}