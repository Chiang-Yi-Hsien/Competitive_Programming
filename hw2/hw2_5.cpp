#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string pokern[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    string pokers[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    int T, mth, method, pushin;
    string methodget;
    vector<int> suf[101], temp, ans;

    cin >> T;
    while (T--)
    {
        cin >> mth;
        for (int i = 1; i <= mth; i++)
        {
            suf[i].push_back(0);
            for (int j = 1; j <= 52; j++)
            {
                cin >> pushin;
                suf[i].push_back(pushin);
            }
        }
        for (int i = 0; i <= 52; i++)
        {
            temp.push_back(i);
            ans.push_back(i);
        }
        cin.ignore();

        while (getline(cin, methodget) && methodget.length())
        {
            istringstream ss(methodget);
            ss >> method;
            for (int i = 1; i <= 52; i++)
                temp[i] = ans[suf[method][i]];
            for (int i = 1; i <= 52; i++)
                ans[i] = temp[i];
        }

        for (int i = 1; i <= 52; i++)
            cout << pokern[(ans[i] - 1) % 13] + " of " + pokers[(ans[i] - 1) / 13]
                 << endl;
        cout << endl;
        for (int i = 1; i <= mth; i++)
            suf[i].clear();
        temp.clear();
        ans.clear();
    }
}