#include <iostream>

using namespace std;


class Node
{
public:
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    LinkedList(int value)       //the constructor
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()           //the destructor
    {
        Node* temp = head;
        while(head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void append(int value)          //method to append a node
    {
        Node* newNode = new Node(value);
        
        if(length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void printList()                //method to print the LL
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }

    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }
};


int main()
{
    LinkedList* myLinkedList = new LinkedList(1);

    myLinkedList->append(5);        //calling the append method (we can either use the arrow operator or dereference myLinkedList then call append() on it.)

    myLinkedList->printList();
}