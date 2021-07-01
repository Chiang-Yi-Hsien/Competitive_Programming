#include <iostream>
#include <string>
using namespace std;
int a[110][110];
void clear()
{
    for (int i = 0; i < 110; i++)
    {
        for (int j = 0; j < 110; j++)
        {
            a[i][j] = 0;
        }
    }
}
void show(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != -1)
                cout << a[i][j];
            else
                cout << '*';
        }
        cout << endl;
    }
}
void process(int n, int m)
{
    int t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            t = 0;
            if (a[i][j] != -1)
            {
                if (a[i - 1][j - 1] == -1)
                    t++;
                if (a[i - 1][j] == -1)
                    t++;
                if (a[i - 1][j + 1] == -1)
                    t++;
                if (a[i][j - 1] == -1)
                    t++;
                if (a[i][j + 1] == -1)
                    t++;
                if (a[i + 1][j - 1] == -1)
                    t++;
                if (a[i + 1][j] == -1)
                    t++;
                if (a[i + 1][j + 1] == -1)
                    t++;
                a[i][j] = t;
            }
        }
    }
}
int main()
{
    int n, m;
    int count = 1;
    string temp = "";
    clear();
    while (cin >> n >> m)
    {
        if (n == 0)
            break;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            for (int j = 0; j < m; j++)
                if (temp[j] == '*')
                    a[i][j + 1] = -1;
        }
        process(n, m);
        if (count != 1)
            cout << endl;
        cout << "Field #" << count++ << ":" << endl;
        show(n, m);
        clear();
    }
}