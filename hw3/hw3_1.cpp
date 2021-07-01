#include <iostream>
#include <string>
using namespace std;
int main()
{
    string t = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";
    string input;
    while (getline(cin, input))
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (t.find(input[i]) < t.size())
                cout << t[t.find(input[i]) - 1];
            else
                cout << input[i];
        }
        cout << endl;
    }
}