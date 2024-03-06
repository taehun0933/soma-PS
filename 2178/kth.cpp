#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

// arr[n][m]

int n, m;
int board[101][101];
int dis[101][101];
queue<pair<int, int>> Q;
int dX[4] = {-1, 0, 1, 0};
int dY[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i{0}; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j{0}; j < s.length(); j++)
            board[i][j] = s[j] - '0';

        fill(dis[i], dis[i] + m, -1);
    }

    // 0 0 0 0

    Q.push({0, 0});
    dis[0][0] = 0;

    while (!Q.empty())
    {
        int curX = Q.front().X;
        int curY = Q.front().Y;
        Q.pop();

        for (int i{0}; i < 4; i++)
        {
            int nX = curX + dX[i];
            int nY = curY + dY[i];

            if (nX < 0 || nX >= n || nY < 0 || nY >= m)
                continue;

            if (dis[nX][nY] != -1 || board[nX][nY] == 0)
                continue;

            Q.push({nX, nY});
            dis[nX][nY] = dis[curX][curY] + 1;
        }
    }

    cout << dis[n - 1][m - 1] + 1;
}