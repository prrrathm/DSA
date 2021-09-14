#include <iostream>
using namespace std;

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

void insertBefore(node* &head, int value){
    node* n = new node(value);
    n->next = head;
    head = n;
}

void displayList(node* head){
    while(head != NULL){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

bool search(node* head, int key){
    while (head != NULL){
        if(head->data == key)
            return true;
        head = head->next;
    }
    return false;
} 

void deleteNode(node* &head, int value){
    if (head == NULL)
        return;
    
    if(head->data == value){
        node* todelete = head;
        head = head->next;
        delete todelete;
        return;
    }

    node* temp = head;
    while(temp->next->data != value){
        temp = temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

int main(){
    node *head = NULL;
    insertAfter(head,1);
    insertAfter(head,1);
    insertAfter(head,3);
    insertAfter(head,4);
    insertBefore(head,0);
    insertBefore(head,-1);
    displayList(head);
    
    cout << search(head,3) << endl;
    
    deleteNode(head,1);
    // deleteAtHead(head);
    displayList(head);
    return 0;
}