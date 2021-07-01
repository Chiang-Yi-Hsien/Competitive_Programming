#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int N, porp, val;
    stack<int> s;
    priority_queue<int> pq;
    queue<int> q;
    bool sflag, pqflag, qflag;
    while (cin >> N)
    {
        while (!s.empty())
            s.pop();
        while (!pq.empty())
            pq.pop();
        while (!q.empty())
            q.pop();
        sflag = true, pqflag = true, qflag = true;

        for (int i = 0; i < N; i++)
        {
            cin >> porp >> val;
            if (porp == 1)
            {
                s.push(val);
                pq.push(val);
                q.push(val);
            }
            if (porp == 2)
            {
                if (s.top() != val)
                    sflag = false;
                if (pq.top() != val)
                    pqflag = false;
                if (q.front() != val)
                    qflag = false;
                s.pop();
                pq.pop();
                q.pop();
            }
        }

        if (!sflag && !pqflag && !qflag)
            cout << "impossible" << endl;
        else if (sflag && !pqflag && !qflag)
            cout << "stack" << endl;
        else if (!sflag && pqflag && !qflag)
            cout << "priority queue" << endl;
        else if (!sflag && !pqflag && qflag)
            cout << "queue" << endl;
        else
            cout << "not sure" << endl;
    }
}