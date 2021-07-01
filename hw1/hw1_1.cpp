#include <iostream>
using namespace std;
int function(int i)
{
    int count = 1;
    while (i != 1)
    {
        if (i % 2)
            i = 3 * i + 1;
        else
            i /= 2;
        count++;
    }
    return count;
}
int main()
{
    int i, j, ans, temp, s;
    while (cin >> i >> j)
    {
        s = 0;
        if (i > j)
        {
            temp = i;
            i = j;
            j = temp;
            s++;
        }
        ans = 0;
        for (int a = i; a <= j; a++)
        {
            if (function(a) > ans)
                ans = function(a);
        }
        if (s == 0)
            cout << i << " " << j << " " << ans << endl;
        else
            cout << j << " " << i << " " << ans << endl;
    }
}
