#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct status
{
    string ATCG;
    int n;
    int index;
};
bool cmp(status a, status b)
{
    if (a.n == b.n)
        return a.index < b.index;
    else
        return a.n < b.n;
}
int main()
{
    int M;
    int n, m;
    vector<status> v;
    status get;
    string temp;
    int id, count;
    cin >> M;
    while (M--)
    {
        cin >> n >> m;
        v.clear();
        id = 0;
        while (m--)
        {
            cin >> temp;
            count = 0;
            for (int i = 0; i < temp.size() - 1; i++)
            {
                for (int j = i + 1; j < temp.size(); j++)
                {
                    if (temp[i] > temp[j])
                        count++;
                }
            }
            get.ATCG = temp;
            get.n = count;
            get.index = id++;
            v.push_back(get);
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); i++)
            cout << v[i].ATCG << endl;
        if (M)
            cout << endl;
    }
}