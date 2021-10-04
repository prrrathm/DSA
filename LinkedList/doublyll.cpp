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

template<typename A> class Doublell{
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
    void append(int value){
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
};

int main(){
  Doublell<int> dll;
  dll.display();
  dll.append(2);
  dll.display();
  return 0;
}
