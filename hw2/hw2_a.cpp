#include <iostream>
using namespace std;
int m[120][120];
int n;
bool check();
int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> m[i][j];
        if (check())
        {
            cout << "OK" << endl;
            continue;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (m[i][j] == 1)
                    m[i][j] = 0;
                else
                    m[i][j] = 1;

                if (check())
                {
                    cout << "Change bit (" << i << "," << j << ")" << endl;
                    break;
                }

                if (m[i][j] == 1)
                    m[i][j] = 0;
                else
                    m[i][j] = 1;
            }
        if (!check())
            cout << "Corrupt" << endl;
    }
}
bool check()
{
    bool flag = true;
    for (int i = 1; i <= n; i++)
        for (int j = 1, sum = 0; j <= n; j++)
        {
            sum += m[i][j];
            if (j == n && sum % 2)
                flag = false;
        }
    for (int j = 1; j <= n; j++)
        for (int i = 1, sum = 0; i <= n; i++)
        {
            sum += m[i][j];
            if (i == n && sum % 2)
                flag = false;
        }
    return flag;
}