#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int T, n;
    vector<string> before, after;
    string temp;
    cin >> T;
    while (T--)
    {
        cin >> n;
        before.clear();
        after.clear();
        cin.ignore();

        for (int i = 0; i < n; i++)
        {
            getline(cin, temp);
            before.push_back(temp);
        }
        for (int i = 0; i < n; i++)
        {
            getline(cin, temp);
            after.push_back(temp);
        }
        reverse(before.begin(), before.end());
        reverse(after.begin(), after.end());

        for (int i = 0; i < before.size();)
        {
            if (before[i] == after[i])
                i++;
            else
                before.erase(before.begin() + i);
        }

        reverse(after.begin(), after.end());
        for (int i = after.size() - before.size() - 1; i >= 0; i--)
            cout << after[i] << endl;
        cout << endl;
    }
}