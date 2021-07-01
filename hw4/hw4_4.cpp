#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int s;
    string input;
    int h1, m1, h2, m2;
    int now_time = 600;
    const int end_time = 1080;
    int day = 1;
    int nap = 0, nap_moment;
    vector<int> start;
    vector<int> end;

    while (cin >> s)
    {
        now_time = 600;
        nap = 0;
        start.clear();
        end.clear();
        cin.ignore();
        if (s == 0)
        {
            cout << "Day #" << day++ << ": the longest nap starts at 10:00 and will last for 8 hours and 0 minutes." << endl;
            continue;
        }

        while (s--)
        {
            getline(cin, input);
            h1 = stoi(input.substr(0, 2));
            m1 = stoi(input.substr(3, 2));
            h2 = stoi(input.substr(6, 2));
            m2 = stoi(input.substr(9, 2));
            start.push_back(h1 * 60 + m1);
            end.push_back(h2 * 60 + m2);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for (int i = 0; i < start.size(); i++)
        {
            if ((start[i] - now_time) > nap)
            {
                nap = (start[i] - now_time);
                nap_moment = now_time;
            }
            now_time = end[i];
        }
        if ((end_time - now_time) > nap)
        {
            nap = (end_time - now_time);
            nap_moment = now_time;
        }

        cout << "Day #" << day++ << ": the longest nap starts at " << nap_moment / 60 << ":";
        if (nap_moment % 60 >= 10)
            cout << nap_moment % 60 << " and will last for ";
        else
            cout << "0" << nap_moment % 60 << " and will last for ";
        if (nap >= 60)
            cout << nap / 60 << " hours and ";
        cout << nap % 60 << " minutes." << endl;
    }
}