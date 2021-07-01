#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
struct CP
{
    double cp_value;
    int index;
};
bool cmp(CP a, CP b)
{
    if (a.cp_value > b.cp_value)
        return true;
    if (a.cp_value < b.cp_value)
        return false;
    return a.index < b.index;
}

int main()
{
    int T, N;
    int day, money, id;
    vector<CP> ans;
    CP temp;
    cin >> T;
    while (T--)
    {
        ans.clear();
        id = 1;
        cin >> N;
        while (N--)
        {
            cin >> day >> money;
            temp.cp_value = (double)money / (double)day;
            temp.index = id++;
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end(), cmp);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i].index;
            if (i != ans.size() - 1)
                cout << " ";
        }

        cout << endl;
        if (T)
            cout << endl;
    }
}