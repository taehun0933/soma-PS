#include <iostream>
#include <algorithm>
using namespace std;

int parent[10001];
pair<int, pair<int, int>> edges[100001];
int v, e;
int minSum;
int connected;

int find(int x)
{
    if (parent[x] == x)
        return x;

    // 사용해야 시간 초과 방지
    return parent[x] = find(parent[x]);
}

int main(void)
{
    cin >> v >> e;
    for (int i{1}; i <= v; i++)
        parent[i] = i;

    for (int i{0}; i < e; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        edges[i].first = z;
        edges[i].second = {x, y};
    }

    sort(edges, edges + e);

    for (int i{0}; i < e; i++)
    {
        int add = edges[i].first;
        pair<int, int> p = edges[i].second;

        int par1 = find(p.first);
        int par2 = find(p.second);

        if (par1 == par2)
            continue;

        parent[par1] = par2;
        minSum += add;
        connected++;

        if (connected == v - 1)
            break;
    }

    cout << minSum;
}