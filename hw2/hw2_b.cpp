#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int N, t;
    bool stay;
    vector<int> v;
    stack<int> s;
    while (cin >> N)
    {
        if (N == 0)
            break;
        stay = true;
        while (stay)
        {
            v.clear();
            while (!s.empty())
                s.pop();
            for (int i = 0; i < N; i++)
            {
                cin >> t;
                if (t == 0)
                {
                    stay = false;
                    cout << endl;
                    break;
                }
                else
                {
                    v.push_back(t);
                }
            }
            if (stay)
            {
                for (int i = 1, count = 0; i <= N; i++)
                {
                    s.push(i);
                    while (!s.empty() && s.top() == v[count])
                    {
                        s.pop();
                        count++;
                    }
                }
                if (s.empty())
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
        }
    }
}