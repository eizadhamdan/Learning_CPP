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
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList()           //the destructor
    {
        Node* temp = head;
        while(head)             //this is the same as while(head != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};
int main()
{
    LinkedList* myLinkedList = new LinkedList(5);

}