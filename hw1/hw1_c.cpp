#include <iomanip>
#include <iostream>
using namespace std;
void f(long long n);
int main()
{
    int t = 1;
    long long n;
    while (cin >> n)
    {
        cout << setw(4) << t << ".";
        if (n != 0)
            f(n);
        else
            cout << " 0";
        cout << endl;
        t++;
    }
}
void f(long long n)
{
    if (n >= 10000000)
    {
        f(n / 10000000);
        cout << " kuti";
        n = n % 10000000;
    }
    if (n >= 100000)
    {
        cout << " " << n / 100000 << " lakh";
        n = n % 100000;
    }

    if (n >= 1000)
    {
        cout << " " << n / 1000 << " hajar";
        n = n % 1000;
    }

    if (n >= 100)
    {
        cout << " " << n / 100 << " shata";
        n = n % 100;
    }

    if (n >= 1)
        cout << " " << n;
}