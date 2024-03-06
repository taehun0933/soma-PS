#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int L, R, C;
char board[31][31][31];
int dis[31][31][31];

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, 0, -1, 0};
int dz[6] = {0, 0, 0, 1, 0, -1};
int exitL, exitR, exitC;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> L >> R >> C)
    {
        if (L == 0 && R == 0 && C == 0)
            break;
        queue<vector<int>> Q;

        for (int i{0}; i < L; i++)
            for (int j{0}; j < R; j++)
                for (int k{0}; k < C; k++)
                {
                    dis[i][j][k] = -1;
                    cin >> board[i][j][k];
                    if (board[i][j][k] == 'S')
                    {
                        vector<int> tmpVec;
                        tmpVec.push_back(i);
                        tmpVec.push_back(j);
                        tmpVec.push_back(k);
                        Q.push(tmpVec);
                        dis[i][j][k] = 0;
                    }

                    if (board[i][j][k] == 'E')
                    {
                        exitL = i;
                        exitR = j;
                        exitC = k;
                    }
                }

        while (!Q.empty())
        {
            vector<int> cur = Q.front();
            Q.pop();

            for (int i{0}; i < 6; i++)
            {
                int nx = cur[0] + dx[i];
                int ny = cur[1] + dy[i];
                int nz = cur[2] + dz[i];

                if (nx < 0 || nx >= L || ny < 0 || ny >= R || nz < 0 || nz >= C)
                    continue;
                if (dis[nx][ny][nz] != -1 || board[nx][ny][nz] == '#')
                    continue;

                dis[nx][ny][nz] = dis[cur[0]][cur[1]][cur[2]] + 1;
                vector<int> tmpVec;
                tmpVec.push_back(nx);
                tmpVec.push_back(ny);
                tmpVec.push_back(nz);
                Q.push(tmpVec);
            }
        }
        if (dis[exitL][exitR][exitC] != -1)
            cout << "Escaped in " << dis[exitL][exitR][exitC] << " minute(s)."
                 << "\n";
        else
            cout << "Trapped!"
                 << "\n";
    }
}