#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

int board[1001][1001];
int dis[1001][1001];
queue<pair<int, int>> Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    for (int i{0}; i < n; i++)
        fill(dis[i], dis[i] + m, -1);

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
            {
                dis[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i{0}; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;

            if (board[nx][ny] == -1 || dis[nx][ny] != -1)
                continue;

            Q.push({nx, ny});
            dis[nx][ny] = dis[cur.first][cur.second] + 1;
        }
    }

    int max{0};
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
        {
            if (dis[i][j] == -1 && board[i][j] == 0)
            {
                cout << "-1";
                return 0;
            }

            if (dis[i][j] > max)
                max = dis[i][j];
        }
    }

    cout << max;
}