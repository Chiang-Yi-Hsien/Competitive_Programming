#include <iostream>
#include <string>
using namespace std;
int main()
{
    int k, q;
    cin >> k;
    string S, check;
    while (k--)
    {
        cin >> S;
        cin >> q;
        while (q--)
        {
            cin >> check;
            if (S.find(check) >= S.size())
                cout << "n" << endl;
            else
                cout << "y" << endl;
        }
    }
}