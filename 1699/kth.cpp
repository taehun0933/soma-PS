#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// DP[i] : i의 제곱수 항의 최소 개수
int DP[100001];
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i{1}; i <= n; i++)
        DP[i] = i;

    for (int i{2}; i <= n; i++)
        for (int j{1}; j * j <= i; j++)
            DP[i] = min(DP[i], DP[i - j * j] + 1);

    cout << DP[n];
}