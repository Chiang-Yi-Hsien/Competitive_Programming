#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int T, r, s, median, distance;
    vector<int> v;
    cin >> T;
    while (T--)
    {
        v.clear();
        distance = 0;
        cin >> r;
        for (int i = 0; i < r; i++)
        {
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        median = v[r / 2];
        for (int i = 0; i < v.size(); i++)
            distance += abs(median - v[i]);
        cout << distance << endl;
    }
}