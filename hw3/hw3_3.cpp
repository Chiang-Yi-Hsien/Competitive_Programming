#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string a, b, ans;
    int count_a, count_b, ans_size;
    while (getline(cin, a) && getline(cin, b))
    {
        ans = "";
        for (int i = 0; i < a.size(); i++)
        {
            if (b.find(a[i]) < b.size() && ans.find(a[i]) >= ans.size())
                ans += a[i];
        }
        ans_size = ans.size();

        for (int i = 0; i < ans_size; i++)
        {
            count_a = 0, count_b = 0;
            for (int j = 0; j < a.size(); j++)
                if (ans[i] == a[j])
                    count_a++;
            for (int k = 0; k < b.size(); k++)
                if (ans[i] == b[k])
                    count_b++;
            if (count_a > count_b)
                count_a = count_b;
            for (int v = 1; v < count_a; v++)
                ans += ans[i];
        }
        sort(ans.begin(), ans.end());
        cout << ans << endl;
    }
}