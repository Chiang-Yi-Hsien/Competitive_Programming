#include <iostream>
using namespace std;
int main()
{
    int K, X, Y, N, M;
    int left1_right2, up1_down2;
    while (cin >> K)
    {
        if (K == 0)
            break;
        cin >> X >> Y;
        for (int i = 0; i < K; i++)
        {
            cin >> N >> M;
            if (N > X)
                left1_right2 = 2;
            if (N < X)
                left1_right2 = 1;
            if (N == X)
                left1_right2 = 0;
            if (M > Y)
                up1_down2 = 1;
            if (M < Y)
                up1_down2 = 2;
            if (M == Y)
                up1_down2 = 0;
            if (left1_right2 == 2 && up1_down2 == 1)
                cout << "NE" << endl;
            else if (left1_right2 == 1 && up1_down2 == 1)
                cout << "NO" << endl;
            else if (left1_right2 == 1 && up1_down2 == 2)
                cout << "SO" << endl;
            else if (left1_right2 == 2 && up1_down2 == 2)
                cout << "SE" << endl;
            else
                cout << "divisa" << endl;
        }
    }
}