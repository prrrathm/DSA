#include <iostream>
using namespace std;

class node{
    public :
        int data;
        node* next;
        node(int value){
            data = value;
        }
};
string displayll(node* head){
    if (head != NULL){
        return "NULL\n";
    }
    cout << head << "->";
    return displayll(head->next);
}

int main(){
    node* head(0);
    displayll(head);
}