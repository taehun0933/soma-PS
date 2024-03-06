#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n, m;
char board[1001][1001];

queue<pair<int, int>> Q;
int dis[1001][1001];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i{0}; i < n; i++)
        fill(dis[i], dis[i] + m, -1);

    for (int i{0}; i < n; i++)
        for (int j{0}; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '2')
            {
                Q.push({i, j});
                dis[i][j] = 0;
            }
            if (board[i][j] == '0')
                dis[i][j] = 0;
        }

    // BFS
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i{0}; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx >= n || nx < 0 || ny >= m || ny < 0)
                continue;

            if (board[nx][ny] == '0' || dis[nx][ny] != -1)
                continue;

            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
            cout << dis[i][j] << " ";
        cout << "\n";
    }
}