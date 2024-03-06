#include <iostream>
#include <algorithm>
using namespace std;

// DP[i][j] : (i,j)에서 가질 수 있는 정사각형의 최댓값
int DP[1001][1001];
bool board[1001][1001];
int n, m;
int maxLen;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i{0}; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j{0}; j < m; j++)
        {
            board[i][j] = s[j] - '0';
            if (board[i][j] == 0)
                DP[i][j] = 0;
            if (i == 0 || j == 0)
                DP[i][j] = board[i][j] == 1 ? 1 : 0;
            maxLen = max(maxLen, DP[i][j]);
        }
    }

    for (int i{1}; i < n; i++)
    {
        for (int j{1}; j < m; j++)
        {
            if (!board[i][j])
                continue;
            if (board[i - 1][j - 1] && board[i - 1][j] && board[i][j - 1])
            {
                DP[i][j] = min({DP[i - 1][j - 1], DP[i - 1][j], DP[i][j - 1]}) + 1;
                maxLen = max(DP[i][j], maxLen);
            }
            else
                DP[i][j] = 1;
        }
    }

    cout << maxLen * maxLen;
}