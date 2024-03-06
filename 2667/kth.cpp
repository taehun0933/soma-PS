#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n;
char board[26][26];
bool vis[26][26];

queue<pair<int, int>> Q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int> sizeS;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
        for (int j{0}; j < n; j++)
            cin >> board[i][j];

    for (int i{0}; i < n; i++)
        for (int j{0}; j < n; j++)
        {
            if (board[i][j] == '1' && !vis[i][j])
            {
                Q.push({i, j});
                vis[i][j] = 1;

                int size{1};
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
                        if (board[nx][ny] != '1' || vis[nx][ny])
                            continue;

                        Q.push({nx, ny});
                        vis[nx][ny] = 1;
                        size++;
                    }
                }
                sizeS.push_back(size);
            }
        }
    sort(sizeS.begin(), sizeS.end());
    cout << sizeS.size() << "\n";
    for (auto i : sizeS)
        cout << i << "\n";
}