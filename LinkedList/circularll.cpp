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
        Node<A>* temp = head;
        while(temp->next != head){
            cout <<temp->data <<"->";
            temp = temp->next;
        }
        cout << temp->data << "->...\n";
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
        if(index>size() || index<0){
            cout << "Invalid Index";
            return;
        }
        Node<A>* temp = head;
        for(int i=1; i<index-1; i++){
            temp = temp->next;
        }
        Node<A>* temp2 = temp->next;
        temp->next = new Node<A>(value);
        temp->next->next = temp2;
    }
    void deleteHead(){
        Node<A>* temp = head;
        Node<A>* end = head;
        while(end->next != head){
            end = end->next;
        }
        end->next = head->next;
        head = head->next;
        delete temp;
    }
    void deleteTail(){
        Node<A>* tempend = head;
        while(tempend->next->next != head){
            tempend = tempend->next;
        }
        Node<A>* end = tempend->next;
        tempend->next = head;
        delete end;
    }
    void deleteAt(int index){
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
    cll.insertNext(2);
    cll.insertNext(3);
    cll.insertNext(4);
    cll.insertHead(1);
    cll.insertHead(0);
    cll.insertAt(3,5);
    cll.display();
    cll.deleteHead();
    cll.deleteTail();
    cll.deleteAt(2);
    cll.display();
    cout << cll.search(3) << endl;
    return 0;
}