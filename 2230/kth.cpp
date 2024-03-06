#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100001];
int minVal{0x7fffffff};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i{0}; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    // y-x >= m
    // y >= x+m
    // x를 고르고, x+m의 값으로 lower_bound 실행.
    for (int i{0}; i < n; i++)
    {
        int x = a[i];
        int y = x + m;

        int *p = lower_bound(a, a + n, y);
        if (p - a == n)
            continue;

        int lower = *p;
        if (lower == y)
        {
            cout << y - x;
            return 0;
        }

        minVal = min(minVal, lower - x);
    }
    cout << minVal;
}