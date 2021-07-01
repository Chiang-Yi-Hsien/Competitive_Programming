#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, t;
    int G, n;
    while (cin >> G)
    {
        if (G == 0)
            break;
        cin >> s;
        n = s.size() / G;

        int head = 0;
        for (int i = 0; i < G; i++, head += n)
        {
            t = s.substr(head, n);
            reverse(t.begin(), t.end());
            cout << t;
        }
        for (int i = s.size() - 1; i >= head; i--)
            cout << s[i];
        cout << endl;
    }
}