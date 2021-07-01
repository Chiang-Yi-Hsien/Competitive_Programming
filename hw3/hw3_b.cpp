#include <iostream>
#include <string>
using namespace std;
int main()
{
    string irr[30][2], S;
    int L, N;
    bool special;
    cin >> L >> N;
    for (int i = 0; i < L; i++)
        cin >> irr[i][0] >> irr[i][1];
    while (N--)
    {
        cin >> S;
        special = false;
        for (int i = 0; i < L; i++)
        {
            if (S == irr[i][0])
            {
                cout << irr[i][1] << endl;
                special = true;
                break;
            }
        }
        if (special)
            continue;

        if (S[S.size() - 1] == 'y' && S[S.size() - 2] != 'a' && S[S.size() - 2] != 'e' && S[S.size() - 2] != 'i' && S[S.size() - 2] != 'o' && S[S.size() - 2] != 'u')
        {
            for (int i = 0; i < S.size() - 1; i++)
                cout << S[i];
            cout << "ies" << endl;
        }
        else if (S[S.size() - 1] == 'o' || S[S.size() - 1] == 's' || S[S.size() - 1] == 'x' || (S[S.size() - 2] == 'c' && S[S.size() - 1] == 'h') || (S[S.size() - 2] == 's' && S[S.size() - 1] == 'h'))
            cout << S << "es" << endl;
        else
            cout << S << 's' << endl;
    }
}