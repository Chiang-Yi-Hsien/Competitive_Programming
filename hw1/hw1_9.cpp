#include <iostream>
using namespace std;
int main()
{
    int T;
    int e, f, c;
    int ans;
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> e >> f >> c;
        e = e + f;
        while (e >= c)
        {
            e = e - c;
            e++;
            ans++;
        }
        cout << ans << endl;
    }
}