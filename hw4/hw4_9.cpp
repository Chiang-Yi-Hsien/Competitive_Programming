#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int t;
    while (cin >> t)
    {
        v.push_back(t);
        sort(v.begin(), v.end());
        if (v.size() % 2)
            cout << v[v.size() / 2] << endl;
        else
            cout << (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2 << endl;
    }
}