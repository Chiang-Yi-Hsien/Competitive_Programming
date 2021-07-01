#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, temp;
    bool jolly;
    vector<int> v;
    vector<int> check;
    while (cin >> n)
    {
        jolly = true;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        if (n > 1)
        {
            for (int i = 1; i < n; i++)
            {
                int get = abs(v[i] - v[i - 1]);
                if (get > (n - 1) || get < 1)
                    jolly = false;
                for (int j = 0; j < check.size(); j++)
                {
                    if (check[j] == get)
                        jolly = false;
                }
                check.push_back(get);
            }
        }
        if (jolly)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;

        v.clear();
        check.clear();
    }
}