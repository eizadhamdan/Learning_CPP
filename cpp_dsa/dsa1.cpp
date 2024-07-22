#include <iostream>


using namespace std;


void printItems(int n);

int main()
{
    int n;
    cout << "Please enter a number:";
    cin >> n;

    printItems(n);




    return 0;
}


void printItems(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << i << j << endl;                         //O(n^2)
        }
    }

    for (int k = 0; k < n; k++)
    {
        cout << k << endl;                              //O(n)
    }                                                           //O(n^2 + n = n^2)
    
}
