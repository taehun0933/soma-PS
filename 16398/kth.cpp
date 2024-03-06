#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int board[1001][1001];
long long costNeed;

// 비용 - 시작점 - 도착점 순서
vector<vector<int>> constInfo;
int parent[1001];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    if (n == 1)
    {
        cout << 0;
        return 0;
    }

    for (int i{1}; i <= n; i++)
    {
        for (int j{1}; j <= n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] != 0)
            {
                vector<int> tmpVec;
                tmpVec.push_back(board[i][j]);
                tmpVec.push_back(i);
                tmpVec.push_back(j);
                constInfo.push_back(tmpVec);
            }
        }
    }

    sort(constInfo.begin(), constInfo.end());

    for (int i{1}; i <= n; i++)
        parent[i] = i;

    int connected{0};
    for (auto v : constInfo)
    {
        int cost = v[0];

        int par1 = find(v[1]);
        int par2 = find(v[2]);

        if (par1 != par2)
        {
            connected++;
            costNeed += cost;
            parent[par2] = par1;

            if (connected == n - 1)
            {
                cout << costNeed;
                return 0;
            }
        }
    }
}