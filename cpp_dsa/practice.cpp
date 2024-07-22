#include <iostream>


using namespace std;

int main()
{
    int n;

    cout << "Enter a number: " << endl;
    cin >> n;

    while(n > 0)
    {
        for(int i = 0; i < n; i++)
        {
            cout << "*";
        }
        n -= 1;
        cout << endl;
    }


    return 0;
}