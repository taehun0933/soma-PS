#include <iostream>
using namespace std;

long long DP[91];
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 1;
    for (int i{3}; i <= n; i++)
        DP[i] = DP[i - 1] + DP[i - 2];

    cout << DP[n];
}