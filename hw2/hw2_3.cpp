#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T, N, P, hi, ans;
    int data[4000] = {0};
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> N >> P;
        for (int p = 0; p < P; p++)
        {
            cin >> hi;
            for (int i = 1; i <= N; i++)
            {
                if (i % 7 != 6 && i % 7 != 0 && i % hi == 0)
                {
                    if (data[i] == 0)
                    {
                        ans++;
                        data[i] = 1;
                    }
                }
            }
        }
        for (int i = 0; i < 4000; i++)
            data[i] = 0;
        cout << ans << endl;
    }
}
