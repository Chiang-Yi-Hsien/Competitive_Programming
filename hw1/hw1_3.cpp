#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int n;
    priority_queue<int> v;
    int temp;
    int dollar, cent, sum, avg, r, ans1;
    while (cin >> n)
    {
        if (n == 0)
            break;
        sum = 0, ans1 = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d.%d", &dollar, &cent);
            temp = dollar * 100 + cent;
            v.push(temp);
            sum += temp;
        }
        r = sum % n;
        avg = sum / n;
        for (int i = 0; i < n; i++)
        {
            if (i < r)
                ans1 += abs(v.top() - (avg + 1));
            else
                ans1 += abs(avg - v.top());
            v.pop();
        }
        cout << "$" << fixed << setprecision(2) << ans1 / 200.0 << endl;
    }
}