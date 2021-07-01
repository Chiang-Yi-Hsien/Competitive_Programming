#include <iostream>
#include <string>
using namespace std;
int main()
{
    int N;
    string s, t;
    bool flag;
    cin >> N;
    while (N--)
    {
        cin >> s;
        for (int i = 1; i <= s.size(); i++)
        {
            if (s.size() % i != 0)
                continue;
            t = s.substr(0, i);
            flag = true;
            for (int j = 0; j < s.size(); j += i)
            {
                if (t != s.substr(j, i))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                cout << i << endl
                     << endl;
                break;
            }
        }
    }
}