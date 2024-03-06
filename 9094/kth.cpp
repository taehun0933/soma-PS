#include <iostream>
using namespace std;

int t, n, m;
int coins[21];

// DP[i] : i원을 만들기 위해 필요한 모든 방법의 수
int DP[10001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while (t--)
    {
        cin >> n;
        for (int i{0}; i < n; i++)
            cin >> coins[i];
        cin >> m;
    }
}