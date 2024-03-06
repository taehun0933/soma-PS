#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

bool board[1001][1001];
int dis[1001][1001];
int dis_end[1001][1001];
int n, m;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int minDis{0x7fffffff};

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
            dis[i][j] = -1;
            dis_end[i][j] = -1;
            board[i][j] = s[j] - '0';
        }
    }

    queue<pair<int, int>> Q;
    queue<pair<int, int>> Q_END;
    Q.push({0, 0});
    Q_END.push({n - 1, m - 1});
    dis[0][0] = 1;
    dis_end[n - 1][m - 1] = 1;

    while (!Q_END.empty())
    {
        pair<int, int> cur = Q_END.front();
        Q_END.pop();
        for (int i{0}; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 1 && dis_end[nx][ny] == -1)
            {
                dis_end[nx][ny] = dis_end[cur.X][cur.Y] + 1;
                continue;
            }
            if (dis_end[nx][ny] != -1)
                continue;

            Q_END.push({nx, ny});
            dis_end[nx][ny] = dis_end[cur.X][cur.Y] + 1;
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (cur.X == n - 1 && cur.Y == m - 1)
        {
            minDis = dis[cur.X][cur.Y];
            break;
        }

        for (int i{0}; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (board[nx][ny] == 1 && dis[nx][ny] == -1)
            {
                dis[nx][ny] = dis[cur.X][cur.Y];
                continue;
            }
            if (dis[nx][ny] != -1)
                continue;

            Q.push({nx, ny});
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
        }
    }

    for (int i{0}; i < n; i++)
        for (int j{0}; j < m; j++)
            if (board[i][j] == 1 && dis[i][j] != -1 && dis_end[i][j] != -1)
                minDis = min(minDis, dis[i][j] + dis_end[i][j]);

    if (minDis == 0x7fffffff)
        cout << -1;
    else
        cout << minDis;
    return 0;
}