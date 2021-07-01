#include <iostream>
#include <vector>
using namespace std;
int cp(int i, int j);
void once(vector<int> &v, int tuple);
int check(vector<int> v, int tuple);
void show(vector<int> v, int size)
{
    for (int i = 0; i < size; i++)
        cout << v[i] << " ";
    cout << endl;
}
int main()
{
    int T, tuple, temp, ans;
    vector<int> v;
    cin >> T;
    while (T--)
    {
        cin >> tuple;
        ans = 0;
        for (int i = 0; i < tuple; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        for (int i = 0; i < 1000; i++)
        {
            once(v, tuple);
            if (check(v, tuple))
            {
                ans = 1;
                break;
            }
        }
        if (ans)
            cout << "ZERO" << endl;
        else
            cout << "LOOP" << endl;
        v.clear();
    }
}

int cp(int i, int j)
{
    int ans;
    if (i > j)
        ans = i - j;
    else
        ans = j - i;
    return ans;
}

void once(vector<int> &v, int tuple)
{
    int z = v[0];
    for (int i = 0; i < tuple; i++)
    {
        if (i != tuple - 1)
            v[i] = cp(v[i], v[i + 1]);
        else
            v[i] = cp(v[i], z);
    }
}

int check(vector<int> v, int tuple)
{
    int temp = 0, ans;
    for (int i = 0; i < tuple; i++)
    {
        if (v[i] == 0)
            temp++;
    }
    if (temp == tuple)
        ans = 1;
    else
        ans = 0;
    return ans;
}