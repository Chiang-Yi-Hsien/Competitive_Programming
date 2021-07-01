#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int T, P, N;
    const int max_size = 5000;
    int adj[max_size][max_size], Erdos[max_size];
    int pp, p_num;
    map<string, int> Name_Num;
    string temp, input;
    vector<int> v;
    queue<int> q;

    cin >> T;
    for (int t = 1; t <= T; t++)
    {

        //initialize
        for (int i = 0; i < p_num; i++)
        {
            for (int j = 0; j < p_num; j++)
                adj[i][j] = 0;
            Erdos[i] = 0;
        }
        pp = 0;
        p_num = 0;
        Name_Num.clear();
        //initialize end

        cin >> P >> N;
        cin.ignore();
        for (int i = 0; i < P; i++)
        {
            getline(cin, input);
            v.clear();
            for (int i = 0, s_pos = 0; i < input.size(); i++)
            {
                if (input[i] == ':')
                    break;
                if ((input[i] == '.') && (input[i + 1] == ',' || input[i + 1] == ':'))
                {
                    temp = input.substr(s_pos, i - s_pos + 1);
                    s_pos = i + 3;
                    if (Name_Num.find(temp) == Name_Num.end())
                    {
                        Name_Num.insert(make_pair(temp, pp++));
                        v.push_back(pp - 1);
                        p_num++;
                    }
                    else
                        v.push_back(Name_Num.find(temp)->second);
                }
            }
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[i] == v[j])
                        continue;
                    else
                        adj[v[i]][v[j]] = adj[v[j]][v[i]] = 1;
                }
            }
        }

        //bfs
        q.push(Name_Num.find("Erdos, P.")->second);
        Erdos[q.front()] = 0;
        bool visit[max_size] = {false};
        while (!q.empty())
        {
            for (int i = 0; i < p_num; i++)
            {
                if (q.front() == i)
                    continue;
                if (adj[q.front()][i] == 1 && visit[i] == false)
                {
                    Erdos[i] = Erdos[q.front()] + 1;
                    q.push(i);
                    visit[i] = true;
                }
            }
            q.pop();
        }
        //bfs end

        cout << "Scenario " << t << endl;
        for (int i = 0; i < N; i++)
        {
            getline(cin, temp);
            if (Name_Num.find(temp) == Name_Num.end() || Erdos[Name_Num.find(temp)->second] == 0)
                cout << temp << " infinity" << endl;
            else
                cout << temp << " " << Erdos[Name_Num.find(temp)->second] << endl;
        }
    }
}