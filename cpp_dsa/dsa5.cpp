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
    Node *head; // pointer to a node
    Node *tail;
    int length;

public:
    LinkedList(int value)
    {                                    // this is a constructor
        Node *newNode = new Node(value); // also a pointer to a node
        head = newNode;
        tail = newNode;
        length = 1;
    }
};

int main()
{
    LinkedList *myLinkedList = new LinkedList(4); // making a new linked list

    return 0;
}