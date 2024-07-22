#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* left;
    Node* right;

    Node(int value)         //constructor for the node class
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
private:
    Node* root;
public:
    BinarySearchTree()
    {
        root = nullptr;
    }
};

int main()
{
    BinarySearchTree bst;

    return 0;
}