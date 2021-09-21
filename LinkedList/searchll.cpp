#include <iostream>
using namespace std;

class node{
    public :
        int data;
        node* next;
        node(int value) {
            data = value;
        }
};

void displayll(node* head){
    if (head == NULL){
        cout << "NULL\n";
        return;
    }
    cout << head->data << "->";
    displayll(head->next);
}

void insertll(node* &head, int value){
    if (head == NULL){
        head = new node(value);
        return;
    }
    insertll(head->next, value);
}

bool searchll(node* head, int key){
    if(head == NULL){
        return false;
    }
    if(head->data == key){
        return true;
    }
    return searchll(head->next, key);
}

int main(){
    node* head = new node(0);
    insertll(head, 1);
    displayll(head);
    cout << searchll(head, 4);
}