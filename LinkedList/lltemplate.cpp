#include <iostream>
using namespace std;

template <typename T> class Node{
    public :
        T data = 1;
        Node<T> *next;
        Node(T value){
            data = value;
            next = NULL;
        }
        Node(const Node *a){
            this->data = a->data;
            this->next = a->next;
        }
        Node & operator=(const Node& a){
            return *this;
        }
        
        void insertNext(T value){
            if (this->next == NULL){
                this->next = new Node<int>(value);
                return;
            }
            this->next->insertNext(value);
        }
        void display(){
            if(this == NULL){
                cout << "NULL\n";
                return;
            }
            cout << this->data << "->";
            this->next->display();
        }
        void insertBefore(T value){
            // Node<T> *temp = new Node<T>(this->data);
            // temp->next = this->next;
            Node<T> *temp = new Node<int>(this);
            this->data = value;
            this->next = temp;
        }
        void insertAt(int key, T value){
            if(key == 1){
                Node<T> *temp = new Node<int>(this);
                this->data = value;
                this->next = temp;
                return;
            }
            this->next->insertAt(key-1, value);
        }
};

int main(){
    Node<int> *head = new Node<int>(0);
    head->insertNext(1);
    head->insertBefore(2);
    head->display();
    head->insertAt(2, 3);
    head->display();
    return 0;
}