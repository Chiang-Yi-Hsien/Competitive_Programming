#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M, t;
bool cmp(int a, int b)
{
    if (a % M != b % M)
        return a % M < b % M;
    if ((a % 2) == 0 && (b % 2) == 0)
        return a < b;
    if ((a % 2) != 0 && (b % 2) != 0)
        return a > b;
    if ((a % 2) != 0 && (b % 2) == 0)
        return true;
    if ((a % 2) == 0 && (b % 2) != 0)
        return false;
    return true;
}
int main()
{
    vector<int> v;
    while (cin >> N >> M)
    {
        v.clear();
        if (N == 0 && M == 0)
            break;
        for (int i = 0; i < N; i++)
        {
            cin >> t;
            v.push_back(t);
        }
        sort(v.begin(), v.end(), cmp);
        cout << N << " " << M << endl;
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
    }
    cout << "0 0" << endl;
}