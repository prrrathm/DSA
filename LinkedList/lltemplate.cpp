#include <iostream>
using namespace std;

template<typename T>class Node{
  private:
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
      void display(){
        while(head != NULL){
          cout << head->data << "->";
          head = head->next;
        }
        cout << "NULL\n";
      }
      void insertNext(T value){
          if(head == NULL){
            head = new Node<T>(value);
            return;
          }
      }
      void inserBefore(T value){
        Node<T>* temp = head;
        head = new Node<T>(value);
        head->next = temp;
      }

};

int main(){
  LinkedList<int> A;
  A.insertNext(1);
  A.inserBefore(2);
  A.display();
  return 0;
}
