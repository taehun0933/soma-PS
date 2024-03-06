#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int n, m;
int board[9][9];
bool vis[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> wallPos;
vector<pair<int, int>> canWallPos;

int maxVal;

void BFS(queue<pair<int, int>> Q)
{
    for (auto p : wallPos)
        board[p.X][p.Y] = 1;

    int virusSafe{0};

    bool tmpVis[9][9];
    for (int i{0}; i < n; i++)
        for (int j{0}; j < m; j++)
        {
            tmpVis[i][j] = vis[i][j];
            if (board[i][j] == 0)
                virusSafe++;
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
            if (board[nx][ny] != 0 || tmpVis[nx][ny])
                continue;

            Q.push({nx, ny});
            tmpVis[nx][ny] = 1;
            virusSafe--;
        }
    }

    maxVal = max(maxVal, virusSafe);

    for (auto p : wallPos)
        board[p.X][p.Y] = 0;
}

// func(k) : k번째로 올 좌표값을 정하는 함수.
void func(int k, int idx, queue<pair<int, int>> &Q)
{
    if (k == 3)
    {
        BFS(Q);
        return;
    }

    for (int i{idx}; i < canWallPos.size(); i++)
    {
        int wallX = canWallPos[i].X;
        int wallY = canWallPos[i].Y;
        wallPos.push_back({wallX, wallY});
        func(k + 1, i + 1, Q);
        wallPos.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    queue<pair<int, int>> Q;

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                canWallPos.push_back({i, j});
            if (board[i][j] == 2)
            {
                Q.push({i, j});
                vis[i][j] = 1;
            }
        }
    }

    // for (auto p : canWallPos)
    //     cout << p.first << " " << p.second << '\n';

    func(0, 0, Q);

    cout << maxVal;
}
