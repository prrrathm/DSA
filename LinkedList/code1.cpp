#include <iostream>
using namespace std;

class node{
    public :
        int data;
        node *next;
};

void push(node** head_ref, int new_data){
    //allocate node
    node* new_node = new node();
    new_node->data =  new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main(){
    node *head = NULL;
    
    return 0;
}