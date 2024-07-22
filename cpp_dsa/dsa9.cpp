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

    void deleteLast()
    {
        if(length == 0)         //if there's nothing in the LL
        {
            return;
        }

        Node* temp = head;          //we have to use to pointers
        Node* pre = head;
        while(temp->next)               //iterate to the last node
        {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;                 //assign tail to the second last node
        tail->next = nullptr;       //now make it point to nullptr(we've gotten rid of the last node)
        length--;                   //update length
        
        if(length == 0)         //corner case(when there's only one node)
        {
            head = nullptr;
            tail = nullptr;
        }
        delete temp;            //free the memory of the deleted node
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
    myLinkedList->append(2);
    myLinkedList->append(3);

    myLinkedList->printList();

    myLinkedList->deleteLast();
    myLinkedList->deleteLast();

    myLinkedList->printList();

    myLinkedList->deleteLast();

    myLinkedList->printList();

}