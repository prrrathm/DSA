#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(){
            data = 0;
        }
        node(int value){
            data = value;
        }
};

void displayll(node* head){
    while (head != NULL) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

void insertAfter(node* &head, int value) {
    node* n = new node(value);
    if(head == NULL) {
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

node* reversell(node* head){
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){

    node *head = NULL;
    insertAfter(head, 1);
    insertAfter(head, 2);
    insertAfter(head, 3);
    displayll(head);
    node* rev = reversell(head);
    displayll(rev);
    return 0;
}