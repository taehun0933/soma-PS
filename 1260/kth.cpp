#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;
bool vis[1001];
vector<int> adj[1001];
queue<int> Q;

void DFS(int cur)
{
    cout << cur << " ";
    vis[cur] = 1;

    for (auto nxt : adj[cur])
    {
        if (vis[nxt])
            continue;

        DFS(nxt);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> v;
    int a, b;
    for (int i{1}; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i{1}; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    // DFS
    DFS(v);

    cout << "\n";
    fill(vis, vis + 1001, 0);

    // BFS
    Q.push(v);
    vis[v] = 1;
    cout << v << " ";
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (auto nxt : adj[cur])
        {
            if (vis[nxt])
                continue;

            Q.push(nxt);
            vis[nxt] = 1;
            cout << nxt << " ";
        }
    }
}