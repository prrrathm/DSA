#include <iostream>
using namespace std;

template <typename T> class Node{
    public :
        int data;
        Node<T> *next;
        Node<T> *prev;
        static bool headEmpty;
        Node(){
            headEmpty = false;
        }
        Node(T value){
            data = value;
            headEmpty = true;
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
            if(this->next == NULL){
                if(headEmpty == true){
                    this->data = value;
                    return;
                }
                this->next = new Node<T>(value);
                return;
            }
            this->next->insertNext(value);
        }
};

int main(){
    Node<int> *head = new Node<int>();
    head->insertNext(1);
    head->display();
    return 0;
}