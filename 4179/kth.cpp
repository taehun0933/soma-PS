#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

char board[1001][1001];
int dis[1001][1001];

int r, c;
queue<pair<int, int>> Q;
pair<int, int> JH;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    for (int i{0}; i < r; i++)
        fill(dis[i], dis[i] + c, -1);

    for (int i{0}; i < r; i++)
        for (int j{0}; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'J')
                JH = {i, j};
            else if (board[i][j] == 'F')
            {
                Q.push({i, j});
                dis[i][j] = 0;
            }
        }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i{0}; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
                continue;
            if (dis[nx][ny] != -1)
                continue;
            if (board[nx][ny] == '#')
                continue;

            Q.push({nx, ny});
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
        }
    }

    Q.push(JH);
    dis[JH.X][JH.Y] = 0;

    // 불 먼저 BFS한 후, 지훈이 움직이기.

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i{0}; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            // 탈출 성공
            if (nx < 0 || nx >= r || ny < 0 || ny >= c)
            {
                cout << dis[cur.X][cur.Y] + 1;
                return 0;
            }

            if (board[nx][ny] == '#')
                continue;

            if (dis[nx][ny] != -1 && dis[nx][ny] <= dis[cur.X][cur.Y] + 1)
                continue;

            Q.push({nx, ny});
            dis[nx][ny] = dis[cur.X][cur.Y] + 1;
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}