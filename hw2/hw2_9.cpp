#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string input;
    vector<int> v;
    while (getline(cin, input))
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == 'B' || input[i] == 'F' || input[i] == 'P' || input[i] == 'V')
                v.push_back(1);
            if (input[i] == 'C' || input[i] == 'G' || input[i] == 'J' || input[i] == 'K' || input[i] == 'Q' || input[i] == 'S' || input[i] == 'X' || input[i] == 'Z')
                v.push_back(2);
            if (input[i] == 'D' || input[i] == 'T')
                v.push_back(3);
            if (input[i] == 'L')
                v.push_back(4);
            if (input[i] == 'M' || input[i] == 'N')
                v.push_back(5);
            if (input[i] == 'R')
                v.push_back(6);
            if (input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U' || input[i] == 'H' || input[i] == 'W' || input[i] == 'Y')
                v.push_back(0);
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (i == 0)
            {
                if (v[i] != 0)
                    cout << v[i];
            }
            else if (v[i] != 0 && v[i] != v[i - 1])
                cout << v[i];
        }
        cout << endl;
        v.clear();
    }
}