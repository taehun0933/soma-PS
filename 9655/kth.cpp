#include <iostream>
using namespace std;

// 돌 i개를 가져갈 때 이기는 사람. true일 경우 상근이가 이기는 것.
bool DP[1001];
int n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    DP[1] = true;
    DP[2] = false;
    DP[3] = true;
    for (int i{4}; i <= n; i++)
    {
        if (DP[i - 3] == false)
            DP[i] = true;
        if (DP[i - 1] == false)
            DP[i] = true;
    }

    if (DP[n] == false)
        cout << "CY";
    else
        cout << "SK";
}