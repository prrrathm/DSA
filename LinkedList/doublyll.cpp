#include <iostream>
using namespace std;

template <typename A> class Node{
  private :
    A data;
    Node<A>* next;
    Node<A>* prev;
    template <typename B> friend class Doublell;
  public:
    Node(){
      this->prev = NULL;
      this->next = NULL;
    }
    Node(A value){
      this->data = value;
      this->prev = NULL;
      this->next = NULL;
    }
};

template<typename A> class Doublell {
  Node<A>* head;
  public:
    Doublell(){
      head = NULL;
    }
    void display(){
      Node<A>* temp = head;
      while(temp != NULL){
        cout << temp->data <<"->";
        temp= temp->next;
      }
      cout << "NULL" << '\n';
    }
    void append(A value){
      if (head == NULL){
        head = new Node<A>(value);
        return;
      }
      Node<A>* temp = head;
      while(temp->next != NULL){
        temp = temp->next;
      }
      temp->next = new Node<A>(value);
      temp->next->prev = temp->next;
    }
    void prepend(A value){
      if(head == NULL){
        head = new Node<int>(value);
        return;
      }
      Node<A>* temp = head;
      head->prev = new Node<A>(value);
      head = head->prev;
      head->next = temp;
    }
    void insert(int index, A value){

    }
};

int main(){
  Doublell<int> dll;
  dll.display();
  dll.append(2);
  dll.append(3);
  dll.prepend(1);
  dll.prepend(0);
  dll.display();
  return 0;
}
