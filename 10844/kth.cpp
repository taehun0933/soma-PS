#include <iostream>
#include <algorithm>
using namespace std;

#define DIVISION 1000000000

// DP[i] : 길이가 i인 계단수
long long DP[101][10];
int n;
long long res;

// DP[i][j] : 길이가 i이면서 끝이 j인 계단수?
// DP[i][0] => DP[i-1][1]
// DP[i][9] => DP[i-1][8]

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    fill(DP[1] + 1, DP[1] + 10, 1);

    for (int i{2}; i <= 100; i++)
    {
        DP[i][0] = DP[i - 1][1];
        DP[i][9] = DP[i - 1][8];

        for (int j{1}; j <= 8; j++)
            DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % DIVISION;
    }

    cin >> n;
    for (int i{0}; i < 10; i++)
        res += DP[n][i];
    cout << res % DIVISION;
}