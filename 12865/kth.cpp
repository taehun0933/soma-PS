#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int w[101];
int v[101];
// DP[i][j] : i번째 물건을 담는 것을 고려한, 가방이 버틸 수 있는 무게 j까지의 가치의 최대합
int DP[101][100001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i{1}; i <= n; i++)
        cin >> w[i] >> v[i];

    for (int i{1}; i <= k; i++)
        if (i >= w[1])
            DP[1][i] = v[1];

    for (int i{2}; i <= n; i++)
    {
        int curWeight = w[i];
        int curValue = v[i];
        for (int j{1}; j <= k; j++)
        {
            // i번째 물건을 담는 것을 고려함.
            if (j >= curWeight)
            {
                // 현재 i번째 물건을 담을 수 있는 상태.
                // 해당 물건을 담는 경우와, 담지 않고 그대로 가는 경우를 비교하여 최댓값 처리.
                DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - curWeight] + curValue);
            }
            else
                DP[i][j] = DP[i - 1][j];
        }
    }

    cout << DP[n][k];
}