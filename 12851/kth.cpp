#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

pair<int, int> dis[200001];
int n, k;
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    for (int i{0}; i <= 200000; i++)
        dis[i].first = -1;

    Q.push(n);
    dis[n].first = 0;
    dis[n].second = 1;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int i : {cur - 1, cur + 1, cur * 2})
        {
            if (i < 0 || i > 200000)
                continue;
            if (!(dis[i].first == -1 || dis[i].first == dis[cur].first + 1))
                continue;

            Q.push(i);
            dis[i].first = dis[cur].first + 1;
            dis[i].second++;
        }
    }

    cout << dis[k].first << "\n";
    cout << dis[k].second;
}