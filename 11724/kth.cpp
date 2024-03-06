#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<int> v[1001];
bool vis[1001];
queue<int> Q;
int numOfConnected;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;
    for (int i{1}; i <= m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i{1}; i <= n; i++)
    {
        if (vis[i])
            continue;

        Q.push(i);
        vis[i] = 1;
        numOfConnected++;

        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();

            for (auto cn : v[cur])
            {
                if (vis[cn])
                    continue;

                Q.push(cn);
                vis[cn] = 1;
            }
        }
    }
    cout << numOfConnected;
}