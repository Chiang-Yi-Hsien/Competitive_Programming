#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int t, count;
    vector<int> v;
    vector<int> kind;
    while (cin >> t)
    {
        if (find(v.begin(), v.end(), t) == v.end())
            kind.push_back(t);
        v.push_back(t);
    }
    for (int i = 0; i < kind.size(); i++)
    {
        count = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] == kind[i])
                count++;
        }
        cout << kind[i] << " " << count << endl;
    }
}