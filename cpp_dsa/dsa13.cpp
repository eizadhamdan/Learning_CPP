#include <iostream>
#include <limits.h>         //including this for INT_MIN

using namespace std;

/*A stack can be implemented using an array or a linked list or using the inbuilt data structure*/

class Node
{
public:
    int value;
    Node* next;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class Stack
{
private:
    Node* top;
    int height;

public:
    Stack(int value)
    {
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void printStack()
    {
        Node* temp = top;
        while(temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop()
    {
        cout << "Top: " << top->value << endl;
    }

    void getHeight()
    {
        cout << "Height: " << height << endl;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop()
    {
        if(height == 0) return INT_MIN;                 //we need to return a number that we'd never expect to be in our stack of integers
        Node* temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;

        return poppedValue;
    }
};

int main()
{

    Stack* newStack = new Stack(3);

    newStack->push(5);

    newStack->printStack();

    cout << newStack->pop() << endl;

    cout << newStack->pop() << endl;

    cout << newStack->pop() << endl;

    return 0;
}