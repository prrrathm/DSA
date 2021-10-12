#include<iostream>
using namespace std;

template<typename A> class Node{
    public:
        A data;
        Node<A>* next;
        Node(){
            next = NULL;
        }
        Node(A value){
            data = value;
            next = NULL;
        }
};

template<typename A> class circularll{
    Node<A>* head;
    circularll(){
        head = new Node<A>();
    }
    void insertNext(A value){
        if(head == NULL){
            head = new Node<A>(value);
        }
        Node<A>* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new Node<A>(value);
        temp->next->next = head;
    }
};

int main(){

    return 0;
}