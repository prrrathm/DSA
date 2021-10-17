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
        head = NULL;
    }
    int size(){
        int count=1;
        Node<A>* temp = head;
        while(temp->next != head){
            count++;
            temp = temp->next;
        }
        return count;
    }
    void display(){
        if(head == NULL){
            cout<<"linked list is empty"<<endl;
            return;
        }
        // cout<<endl<<"----link list items------"<<endl;
        Node<A>* temp = head;
        while(true){
            cout<<temp->data<<"->";
            temp = temp->next;
            if(temp == head) break;
        }
        cout<<"..."<<endl;
    }
    
    void insertNext(A value){
        if(head == NULL){
            head = new Node<A>(value);
            head->next = head;
            return;
        }
        Node<A>* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = new Node<A>(value);
        temp->next->next = head;
    }
    void insertHead(A value){
        if(head == NULL){
            head = new Node<A>(value);
            head->next = head;
            return;
        }
        Node<A>* temp = head;
        Node<A>* end = head;
        while(end->next != head){
            end = end->next;
        }
        head = new Node<A>(value);
        head->next = temp;
        end->next = head;
    }
    void insertAt(int index, A value){
        if(index > size() || index < 0){
            cout<<"index out of bound !"<<endl;
            return;
        }
        if(index == 0){
            insertHead(value);
            return;
        }
        Node<A>* node = new Node<A>[1];
        node->data = value;
        int count = 0;
        Node<A>* temp = head;
        while(count < index){
            if(count == index-1){
                node->next = temp->next != head ? temp->next : head;
                temp->next = node;
                cout<<"new node added at index "<<index<<" !"<<endl;
                break;
            }
            count++;
            temp = temp->next;
        }
    }
    void deleteHead(){
        if(head == NULL){
            cout <<"Empty List";
            return;
        }
        if(size() == 1) {
            head == NULL;
            return;
        }
        Node<A>* temp = head;
        Node<A>* end = head;
        head = head->next;
        end->next = head;
        delete temp;
    }
    void deleteTail(){
        if(head == NULL){
            cout <<"Empty List";
            return;
        }
        Node<A>* tempend = head;
        while(tempend->next->next != head){
            tempend = tempend->next;
        }
        Node<A>* end = tempend->next;
        tempend->next = head;
        delete end;
    }
    void deleteAt(int index){
        if(head == NULL){
            cout <<"Empty List";
            return;
        }
        if(index>size() || index<0){
            cout << "Invalid Index";
            return;
        }
        Node<A>* temp = head;
        for(int i=1; i<index-1;i++){
            temp = temp->next;
        }
        Node<A>* temp2 = temp->next;
        temp->next = temp->next->next;
        delete temp2;
    }
    bool search(A key){
        Node<A>* temp = head;
        while(temp->next != head){
            if(temp->data == key){
                return true;
            }
            temp = temp->next;
        }
        if(temp->data == key){
            return true;
        }
        return false;
    }

};

int main(){
    circularll<int> cll;
    // cll.insertNext(2);
    // cll.insertNext(3);
    // cll.insertNext(4);
    cll.insertHead(1);
    cll.insertHead(0);
    cll.insertAt(0,6);
    cll.display();
    // cll.deleteHead();
    // cll.deleteTail();
    // cll.deleteAt(2);
    cll.display();
    return 0;
}