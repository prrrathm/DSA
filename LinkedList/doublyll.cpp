#include <iostream>
using namespace std;

template <class T> class Node{
    public :
        int data;
        Node<T> *head;
        Node<T> *tail;
        Node(T value){
            data = value;
        }
};

int main(){

    return 0;
}