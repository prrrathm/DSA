#include <iostream>
using namespace std;

template <class T> class Node{
    public :
        T data;
        Node<T> *next;
        // Node(T value){
        //     data = value;
        //     next = NULL;
        // }
        void insertNext(T value){
            // Node<T> *tem = this;
            if (this->next == NULL){
                this->next = new Node;
                this->next->data = value;
                return;
            }
            this->next->insertNext(value);
        }
};

template <class T> void insertNex(Node<T> head, int value);

int main(){
    Node<int> *head(0);
    head->insertNext(1);
    return 0;
}