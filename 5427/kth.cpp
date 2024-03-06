#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int t, w, h;
char board[1001][1001];

#define X first
#define Y second

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while (t--)
    {
        cin >> w >> h;
        queue<pair<int, int>> Q_fire;
        queue<pair<int, int>> Q_sanggeun;
        int dis_fire[1001][1001];
        int dis_sanggeun[1001][1001];

        for (int i{0}; i < h; i++)
        {
            for (int j{0}; j < w; j++)
            {
                cin >> board[i][j];

                dis_fire[i][j] = -1;
                dis_sanggeun[i][j] = -1;

                if (board[i][j] == '@')
                {
                    dis_sanggeun[i][j] = 0;
                    Q_sanggeun.push({i, j});
                }
                if (board[i][j] == '*')
                {
                    dis_fire[i][j] = 0;
                    Q_fire.push({i, j});
                }
            }
        }

        // 불 먼저 ㄱㄱ
        while (!Q_fire.empty())
        {
            pair<int, int> cur = Q_fire.front();
            Q_fire.pop();

            for (int i{0}; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                    continue;
                if (board[nx][ny] == '#' || dis_fire[nx][ny] != -1)
                    continue;

                Q_fire.push({nx, ny});
                dis_fire[nx][ny] = dis_fire[cur.X][cur.Y] + 1;
            }
        }

        bool canExit{0};
        // 상근이 탈출시키기
        while (!Q_sanggeun.empty() && !canExit)
        {
            pair<int, int> cur = Q_sanggeun.front();
            Q_sanggeun.pop();

            for (int i{0}; i < 4; i++)
            {
                int nx = cur.X + dx[i];
                int ny = cur.Y + dy[i];

                if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                {
                    cout << dis_sanggeun[cur.X][cur.Y] + 1 << "\n";
                    canExit = 1;
                    break;
                }
                if (board[nx][ny] == '#' || dis_sanggeun[nx][ny] != -1)
                    continue;
                if (dis_fire[nx][ny] != -1 && dis_fire[nx][ny] <= dis_sanggeun[cur.X][cur.Y] + 1)
                    continue;

                Q_sanggeun.push({nx, ny});
                dis_sanggeun[nx][ny] = dis_sanggeun[cur.X][cur.Y] + 1;
            }
        }

        if (!canExit)
            cout << "IMPOSSIBLE\n";
    }
}