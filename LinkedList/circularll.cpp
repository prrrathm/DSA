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
    public:
    Node<A>* head;
    circularll(){
        head = new Node<A>();
    }
    void display(){
        Node<A>* temp = head;
        while(temp->next != head){
            cout <<temp->data <<"->";
            temp = temp->next;
        }
        cout << "-^\n";
    }
    void insertNext(A value){
        if(head == NULL){
            head = new Node<A>(value);
            head->next = head;
            cout<< head->data;
            return;
        }
        // Node<A>* temp = head;
        // while(temp->next != head){
        //     temp = temp->next;
        // }
        // cout << temp->data;
        // temp->next = new Node<A>(value);
        // temp->next->next = head;
    }
    void insertHead(A value){
        
    }
};

int main(){
    circularll<int> cll;
    cll.insertNext(2);
    // cll.display();
    return 0;
}