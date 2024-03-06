#include <iostream>
#include <cmath>
using namespace std;

int n, k;

void func(int n, int start, int end)
{
    if (n == 1)
    {
        k++;
        cout << start << " " << end << "\n";
        return;
    }

    int put;

    if (start == 1)
    {
        if (end == 2)
            put = 3;
        else // end == 3
            put = 2;
    }
    else if (start == 2)
    {
        if (end == 1)
            put = 3;
        else // end == 3
            put = 1;
    }
    else // start == 3
    {
        if (end == 1)
            put = 2;
        else // end == 2
            put = 1;
    }

    func(n - 1, start, put);

    // 나머지 하나를 배치
    k++;
    cout << start << " " << end << "\n";

    if (end == 1)
        func(n - 1, put, end);
    else if (end == 2)
        func(n - 1, put, end);
    else
        func(n - 1, put, end);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    long long res = pow(2, n) - 1;
    cout << res << "\n";
    func(n, 1, 3);
}