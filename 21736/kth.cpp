#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char board[601][601];
bool vis[601][601];
int fr;

#define X first
#define Y second
queue<pair<int, int>> Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'I')
            {
                Q.push({i, j});
                vis[i][j] = 1;
            }
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

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || board[nx][ny] == 'X')
                continue;

            Q.push({nx, ny});
            vis[nx][ny] = 1;
            if (board[nx][ny] == 'P')
                fr++;
        }
    }
    fr != 0 ? cout << fr : cout << "TT";
}