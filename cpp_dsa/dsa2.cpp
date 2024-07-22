#include <iostream>


using namespace std;

int addItems(int n);

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << addItems(n) << endl;

    return 0;
}

int addItems(int n)
{
    return n + n;               //O(1)  constant time
}