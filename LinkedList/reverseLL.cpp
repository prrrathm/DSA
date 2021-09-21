#include <iostream>
using namespace std;

//Reversing a Linked List
//Two ways - iterative and recrusive

class node{
    public :
        int data;
        node *next;
        node(int value){
            data = value;
        }
};

void insertAfter(node* &head, int value){
    
    node* n = new node(value);

    if (head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = n;
}

void displayList(node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

//1. iterative
//We'll use 3 pointers previous current and next
node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr !=  NULL) {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
}

//2. .recrusive

node* reverserecursive(node* head){

    if(head == NULL || head->next==NULL)
        return head;

    node* newhead = reverserecursive(head->next);
    displayList(head);
    displayList(newhead);

    head->next->next = head;
    head->next= NULL;

    displayList(head);
    displayList(newhead);
    cout << endl;
    return newhead;
} 

int main(){
    node *head = NULL;
    insertAfter(head,1);
    insertAfter(head,2);
    insertAfter(head,3);
    insertAfter(head,4);
    insertAfter(head,5);
    // insertBefore(head,0);
    // insertBefore(head,-1);
    cout << endl;
    displayList(head);
    cout << endl << endl;

    head = reverserecursive(head);

    cout << endl << endl;
    displayList(head);

    return 0;
}