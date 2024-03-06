#include <iostream>
using namespace std;

int n;
int DP[31];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    DP[2] = 3;
    DP[4] = 11;
    for (int i{6}; i <= n; i += 2)
    {
        DP[i] += 2;
        DP[i] += DP[i - 2] * 3;
        for (int idx = 4; idx <= i; idx += 2)
            DP[i] += 2 * DP[i - idx];
    }
    cout << DP[n];
}