#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

#define X first;
#define Y second;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;

int n, m;
bool board[501][501];

int numOfPic;
int maxArea;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i{0}; i < n; i++)
        for (int j{0}; j < m; j++)
            cin >> board[i][j];

    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
        {
            if (board[i][j] == 1)
            {
                Q.push({i, j});
                board[i][j] = 0;
                int area = 1;
                numOfPic++;

                while (!Q.empty())
                {
                    int curX = Q.front().X;
                    int curY = Q.front().Y;
                    Q.pop();

                    for (int i{0}; i < 4; i++)
                    {
                        int nX = curX + dx[i];
                        int nY = curY + dy[i];

                        if (nX < 0 || nX >= n || nY < 0 || nY >= m)
                            continue;

                        if (board[nX][nY] == 0)
                            continue;

                        Q.push({nX, nY});
                        board[nX][nY] = 0;
                        area++;
                    }
                }

                if (area > maxArea)
                    maxArea = area;
            }
        }
    }

    cout << numOfPic << "\n"
         << maxArea;
}