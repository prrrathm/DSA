#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <class T>
class SinglyLinkList
{

    Node<T> *head1, *head2;

public:
    SinglyLinkList()
    {
        head1 = NULL;
        head2 = NULL;
    }

    ~SinglyLinkList()
    {
        Node<T> *ptr1 = head1;
        while (head1)
        {
            head1 = head1->next;
            delete ptr1;
            ptr1 = head1;
        }

        Node<T> *ptr2 = head2;
        while (head2)
        {
            head2 = head2->next;
            delete ptr2;
            ptr2 = head2;
        }
    }
    void creatSLink_List1(int);
    void insertAtBeginning(T);
    void insertAtPos(int, T);
    void removeFromBeginning();
    void removeFromPos(int);
    Node<T> *search(T);
    bool empty(Node<T> *);
    int length();
    void creatSLink_List2(int);
    void concatenationTwoLists();
    void display();
};

template <class T>
int SinglyLinkList<T>::length()
{
    Node<T> *ptr = head1;
    int len = 0;
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }
    return len;
}

template <class T>
bool SinglyLinkList<T>::empty(Node<T> *ptr)
{
    if (ptr == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
void SinglyLinkList<T>::insertAtBeginning(T x)
{
    Node<T> *ptr;
    ptr = new Node<T>;

    ptr->next = head1;
    ptr->data = x;
    head1 = ptr;

    cout << endl;
    cout << x << " has been added at beganing !! ";
}

template <class T>
void SinglyLinkList<T>::insertAtPos(int pos, T x)
{
    Node<T> *temp = new Node<T>;
    Node<T> *ptr = head1;

    if (pos <= 0 || pos > length())
    {
        cout << "Error !! Invalid position !!" << endl;
    }
    else
    {
        for (int i = 1; i < pos - 1; i++)
        {
            ptr = ptr->next;
        }
        temp->data = x;
        temp->next = ptr->next;
        ptr->next = temp;

        cout << endl;
        cout << x << " has been added at position " << pos << " !!";
    }
}

template <class T>
void SinglyLinkList<T>::removeFromBeginning()
{
    Node<T> *ptr = head1;
    T x;
    if (empty(ptr))
    {
        cout << "List is Empty !!" << endl;
    }
    else
    {
        x = ptr->data;

        head1 = head1->next; //deleting the element at beganing

        delete ptr;
        cout << x << " has been deleted !!";
    }
}

template <class T>
void SinglyLinkList<T>::removeFromPos(int pos)
{
    Node<T> *ptr = head1;
    Node<T> *temp = new Node<T>;
    T x;
    if (empty(ptr))
    {
        cout << "List is Empty !!" << endl;
    }
    else
    {

        if (pos <= 0 || pos > length())
        {
            cout << "Error !! Invalid position !!" << endl;
        }

        else
        {
            for (int i = 1; i < pos - 1; i++)
            {
                ptr = ptr->next;
            }
            x = (ptr->next)->data;
            temp = (ptr->next)->next;
            ptr->next = temp;
            cout << x << " has been deleted !! ";
        }
    }
}

template <class T>
Node<T> *SinglyLinkList<T>::search(T x)
{
    Node<T> *ptr;
    ptr = new Node<T>;
    ptr = head1;

    bool flag = false;
    while (ptr != NULL)
    {
        if (x == ptr->data)
        {
            flag = true;
            return ptr;
        }
        ptr = ptr->next;
    }
    if (flag == false)
    {
        return NULL;
    }
}

template <class T>
void SinglyLinkList<T>::display()
{
    Node<T> *ptr = head1;
    if (empty(ptr))
    {
        cout << " Empty !!";
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}
template <class T>
void SinglyLinkList<T>::creatSLink_List1(int n)
{
    Node<T> *newNode, *ptr;
    T x;
    head1 = new Node<T>;

    if (empty(head1))
    {
        cout << "\nUnable to allocate memory.";
    }
    else
    {

        cout << "\nEnter the data of node 1: ";
        cin >> x;

        head1->data = x;
        head1->next = NULL;

        ptr = head1;

        for (int i = 2; i <= n; i++)
        {
            newNode = new Node<T>;

            if (empty(newNode))
            {
                cout << "\nUnable to allocate memory.";
                break;
            }
            else
            {
                cout << "Enter the data of node " << i << " = ";
                cin >> x;

                newNode->data = x;
                newNode->next = NULL;

                ptr->next = newNode;
                ptr = ptr->next;
            }
        }
        cout << "\nSingly Linked List 1 created successfully !!";
    }
}

template <class T>
void SinglyLinkList<T>::creatSLink_List2(int n)
{
    Node<T> *newNode, *ptr;
    T x;
    head2 = new Node<T>;

    if (empty(head2))
    {
        cout << "\nUnable to allocate memory.";
    }
    else
    {

        cout << "\nEnter the data of node 1: ";
        cin >> x;

        head2->data = x;
        head2->next = NULL;

        ptr = head2;

        for (int i = 2; i <= n; i++)
        {
            newNode = new Node<T>;

            if (empty(newNode))
            {
                cout << "\nUnable to allocate memory.";
                break;
            }
            else
            {
                cout << "Enter the data of node " << i << " = ";
                cin >> x;

                newNode->data = x;
                newNode->next = NULL;

                ptr->next = newNode;
                ptr = ptr->next;
            }
        }
        cout << "\nSingly Linked List 2 created successfully !!";
    }
}

template <class T>
void SinglyLinkList<T>::concatenationTwoLists()
{
    Node<T> *ptr = head1;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = head2;

    head2 = NULL;
}

int main()
{

    Node<int> *node1 = NULL;
    Node<char> *node2 = NULL;
    int element, pos, choice1, choice2, size;
    char ch, character;
    SinglyLinkList<int> e;
    SinglyLinkList<char> f;

    cout << "\n----Choose What type of Singly Link list you wants to make----";
    cout << "\n1. Integer List";
    cout << "\n2. Character List";
    cout << "\n Enter = ";
    cin >> choice1;

    cout << "Enter no. of elements you wants to add in link 1 = ";
    cin >> size;
    switch (choice1)
    {
    case 1:
        e.creatSLink_List1(size);
        break;
    case 2:
        f.creatSLink_List1(size);
        break;
    default:
        cout << "No Such choice !!";
        break;
    }

    do
    {
        cout << "\n-------Choose what action you want to perform------" << endl;
        cout << "\n1.Insert an element at the beginning." << endl;
        cout << "2.Insert an element at 'i'th position." << endl;
        cout << "3.Remove an element from the beginning." << endl;
        cout << "4.Remove an element from position." << endl;
        cout << "5.Search for an element in the linked list." << endl;
        cout << "6.Size of Linked list." << endl;
        cout << "7.Display the list." << endl;
        cout << "8.Concatenation of Two lists. " << endl;
        cout << "9.Exit the program." << endl;
        cout << "\nEnter your choice = ";
        cin >> choice2;
        switch (choice2)
        {
        case 1:
            if (choice1 == 1)
            {
                cout << "Enter element to be added = ";
                cin >> element;
                e.insertAtBeginning(element);
            }
            else
            {
                cout << "Enter element to be added = ";
                cin >> character;
                f.insertAtBeginning(character);
            }
            break;
        case 2:
            cout << "Enter position at which new node is to be added = ";
            cin >> pos;
            if (choice1 == 1)
            {
                cout << "Enter element to be added = ";
                cin >> element;
                e.insertAtPos(pos, element);
            }
            else
            {
                cout << "Enter element to be added = ";
                cin >> character;
                f.insertAtPos(pos, character);
            }
            break;
        case 3:
            if (choice1 == 1)
            {
                e.removeFromBeginning();
            }
            else
            {
                f.removeFromBeginning();
            }
            break;

        case 4:
            cout << "\nEnter position from which node is to be deleted = ";
            cin >> pos;

            if (choice1 == 1)
            {
                e.removeFromPos(pos);
            }
            else
            {
                f.removeFromPos(pos);
            }
            break;

        case 5:

            if (choice1 == 1)
            {
                cout << "\nEnter element to be Searched: ";
                cin >> element;
                node1 = e.search(element);
                if (node1 == NULL)
                {
                    cout << "\nElement not found !!";
                }
                else
                {
                    cout << "\nElement found at address : " << node1;
                }
            }
            else
            {
                cout << "\nEnter element to be Searched: ";
                cin >> character;
                node2 = f.search(character);
                if (node2 == NULL)
                {
                    cout << "\nElement not found !!";
                }
                else
                {
                    cout << "\nElement found at address : " << node2;
                }
            }
            break;

        case 6:
            if (choice1 == 1)
            {
                cout << "\nList is : ";
                e.display();
                size = e.length();
                cout << "\nLength of the above Linked List is : " << size << endl;
            }
            else
            {
                cout << "\nList is : ";
                f.display();
                size = f.length();
                cout << "\nLength of the above Linked List is : " << size << endl;
            }
            break;

        case 7:
            if (choice1 == 1)
            {
                cout << "\nList is : ";
                e.display();
            }
            else
            {
                cout << "\nList is : ";
                f.display();
            }
            break;

        case 8:
            cout << "Enter no. of elements you wants to add in link 2 = ";
            cin >> size;
            if (choice1 == 1)
            {
                e.creatSLink_List2(size);

                e.concatenationTwoLists();
                cout << "Concatenatd list is : ";
                e.display();
            }
            else
            {
                f.creatSLink_List2(size);

                f.concatenationTwoLists();
                cout << "Concatenatd list is : ";
                f.display();
            }

            break;

        case 9:
            exit(0);
            break;

        default:
            cout << "\nNo Such choice !! Try again...";
            break;
        }
        cout << "\nWant to perform another !! PRESS 'Y'... ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}