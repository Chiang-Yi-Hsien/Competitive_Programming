#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
string S = "the quick brown fox jumps over the lazy dog";
map<char, char> m;
map<char, char>::iterator it;
bool is_solution(string Z)
{
    m.clear();
    if (S.size() != Z.size())
        return false;

    for (int i = 0; i < S.size(); i++)
        if (S[i] == ' ' && Z[i] != ' ')
            return false;

    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != ' ')
        {
            it = m.find(Z[i]);
            if (it != m.end() && it->second != S[i])
                return false;
            m[Z[i]] = S[i];
        }
    }
    return true;
}
int main()
{
    string t;
    vector<string> v;
    int N;
    bool flag;
    cin >> N;
    cin.ignore();
    cin.ignore();
    while (N--)
    {
        v.clear();
        m.clear();
        flag = false;
        while (getline(cin, t))
        {
            if (t == "")
                break;
            v.push_back(t);
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (is_solution(v[i]))
                break;
            if (i == v.size() - 1 && !is_solution(v[i]))
            {
                cout << "No solution." << endl
                     << endl;
                flag = true;
                break;
            }
        }
        if (flag)
            continue;

        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] != ' ')
                    cout << m[v[i][j]];
                else
                    cout << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
}