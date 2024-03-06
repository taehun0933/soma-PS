#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<int> adj[101];
int min_bacon{0x7fffffff};
int baconMan;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int a, b;
    for (int i{1}; i <= m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // BFS를 총 N번 해야 함. => O(N(N+M))의 시간복잡도
    for (int i{1}; i <= n; i++)
    {
        queue<int> Q;
        int dis[101];
        fill(dis, dis + 101, -1);
        int bacon{0};

        Q.push(i);
        dis[i] = 0;
        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();

            for (auto nxt : adj[cur])
            {
                if (dis[nxt] != -1)
                    continue;

                Q.push(nxt);
                dis[nxt] = dis[cur] + 1;
                bacon += dis[nxt];
            }
        }
        if (min_bacon > bacon)
        {
            baconMan = i;
            min_bacon = bacon;
        }
    }
    cout << baconMan;
}