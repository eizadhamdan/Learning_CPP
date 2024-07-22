#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void printList()
    {
        Node* temp = head;
        while(temp)
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

    void append(int value)
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
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast()
    {
        if (length == 0) return;

        Node* temp = tail;

        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
        length--;
    }
};

int main()
{
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);

    myDLL->append(2);

    cout << "DLL before deleteLast():" << endl;
    myDLL->printList();


    myDLL->deleteLast();
    cout << endl << "DLL after first deleteLast():" << endl;
    myDLL->printList();

    myDLL->deleteLast();
    cout << endl << "DLL after second deleteLast():" << endl;
    myDLL->printList();

    myDLL->deleteLast();
    cout << endl << "DLL after third deleteLast():" << endl;
    myDLL->printList();


    return 0;
}