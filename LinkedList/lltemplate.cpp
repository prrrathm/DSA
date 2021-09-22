#include <iostream>
using namespace std;

template <class T> class Node{
    public :
        T data = 1;
        Node<T> *next;
        Node(T value){
            data = value;
            next = NULL;
        }
        void insertNext(T value){
            if (this->next == NULL){
                this = new Node<int>(value);
                return;
            }
            this->next->insertNext(value);
        }
};

template <class T> void insertNex(Node<T> head, int value);

int main(){
    Node<int> *head = new Node<int>(0);
    head->insertNext(1);
    cout<< head->data;
    cout<< head->next;
    return 0;
}