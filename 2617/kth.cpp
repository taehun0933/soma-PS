#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool vis[100];
vector<int> adj[100];
int res;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i{0}; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i{1}; i <= n; i++)
    {
        cout << adj[i].size() << "\n";
        if (adj[i].size() == n - 1)
            res++;
    }

    cout << res;
}