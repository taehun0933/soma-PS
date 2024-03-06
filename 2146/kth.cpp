#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 섬에서의 모든 끝부분 저장
// 앞선 끝부분에서 BFS
// BFS할 때마다 최소 거리를 갱신

#define X first
#define Y second

int board[101][101];
bool vis[101][101];
int bridgeBoard[101][101];
int bridgeDis[101][101];
int minDis{0x7fffffff};

int n;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS(int startX, int startY)
{
    int tmpBoard[101][101];
    int tmpDis[101][101];

    for (int i{0}; i < n; i++)
        for (int j{0}; j < n; j++)
        {
            tmpBoard[i][j] = bridgeBoard[i][j];
            tmpDis[i][j] = bridgeDis[i][j];
        }

    queue<pair<int, int>> Q;
    Q.push({startX, startY});
    int islandNum = board[startX][startY];
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();

        for (int i{0}; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;

            if (tmpBoard[nx][ny] == islandNum)
                continue;
            if (tmpBoard[nx][ny] != islandNum && tmpBoard[nx][ny] != 0)
            {
                minDis = min(minDis, tmpDis[cur.X][cur.Y]);
                return;
            }
            if (tmpDis[nx][ny] != -1)
                continue;

            Q.push({nx, ny});
            tmpDis[nx][ny] = tmpDis[cur.X][cur.Y] + 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    queue<pair<int, int>> Q;
    queue<pair<int, int>> bridgeQ;
    int islandNum{0};
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < n; j++)
        {
            if (board[i][j] && !vis[i][j])
            {
                islandNum++;
                Q.push({i, j});
                vis[i][j] = 1;
                board[i][j] = islandNum;
                while (!Q.empty())
                {
                    pair<int, int> cur = Q.front();
                    Q.pop();

                    for (int i{0}; i < 4; i++)
                    {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];

                        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                            continue;
                        if (vis[nx][ny])
                            continue;
                        if (board[nx][ny] == 0)
                        {
                            bridgeQ.push({cur.X, cur.Y});
                            continue;
                        }
                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                        board[nx][ny] = islandNum;
                    }
                }
            }
        }
    }

    while (!bridgeQ.empty())
    {
        pair<int, int> cur = bridgeQ.front();
        bridgeQ.pop();

        bridgeBoard[cur.X][cur.Y] = board[cur.X][cur.Y];
        bridgeDis[cur.X][cur.Y] = 1;
    }

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < n; j++)
        {
            bridgeDis[i][j] = -1;
            if (bridgeBoard[i][j] != 0)
            {
                bridgeQ.push({i, j});
                bridgeDis[i][j] = 0;
            }
        }
    }

    while (!bridgeQ.empty())
    {
        pair<int, int> cur = bridgeQ.front();
        bridgeQ.pop();

        BFS(cur.X, cur.Y);
    }
    cout << minDis;
}