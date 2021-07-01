#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int N, M;
    int count = 1;
    vector<string> judge;
    vector<string> submit;
    string judge_num, submit_num, temp;
    while (1)
    {
        judge.clear();
        submit.clear();
        judge_num = "";
        submit_num = "";

        cin >> N;
        if (N == 0)
            break;
        cin.ignore();
        while (N--)
        {
            getline(cin, temp);
            judge.push_back(temp);
        }

        cin >> M;
        cin.ignore();
        while (M--)
        {
            getline(cin, temp);
            submit.push_back(temp);
        }

        if (judge == submit)
        {
            cout << "Run #" << count++ << ": Accepted" << endl;
            continue;
        }

        for (int i = 0; i < judge.size(); i++)
        {
            for (int j = 0; j < judge[i].size(); j++)
            {
                if (judge[i][j] >= '0' && judge[i][j] <= '9')
                    judge_num += judge[i][j];
            }
        }
        for (int i = 0; i < submit.size(); i++)
        {
            for (int j = 0; j < submit[i].size(); j++)
            {
                if (submit[i][j] >= '0' && submit[i][j] <= '9')
                    submit_num += submit[i][j];
            }
        }

        if (judge_num == submit_num)
            cout << "Run #" << count++ << ": Presentation Error" << endl;
        else
            cout << "Run #" << count++ << ": Wrong Answer" << endl;
    }
}