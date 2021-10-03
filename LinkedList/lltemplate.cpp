#include <iostream>
using namespace std;

template<typename T>class Node{
  public:
        T data;
        Node<T>* next;
        template<typename U>friend class LinkedList;
    public:
        Node(){
            this->next = NULL;
        }
        Node(T value){
            this->data = value;
            this->next = NULL;
        }
};
template<typename T>class LinkedList{
    private:
        Node<T>* head;
    public:
        LinkedList(){
            this->head = NULL;
        }
        void insertNext(T value){
            if(head == NULL){
                head = new Node<T>(value);
                return;
            }
        }
        void display(){
          while(head != NULL){
            cout << head->data << "->";
            head = head->next;
          }
            cout << "NULL\n";
        }
};

int main(){
  LinkedList<int> A;
  A.insertNext(1);
  // cout << A.data;
  A.display();
  return 0;
}
