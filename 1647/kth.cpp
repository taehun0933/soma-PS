#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 유지비 존재
// 마을을 두 개의 분리된 마을로 분할
vector<vector<int>> edges;
int n, m;
int parent[100001];
int minCost;

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
    cin >> n >> m;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> tmpVec;
        tmpVec.push_back(c);
        tmpVec.push_back(a);
        tmpVec.push_back(b);
        edges.push_back(tmpVec);
    }

    sort(edges.begin(), edges.end());

    for (int i{1}; i <= n; i++)
        parent[i] = i;

    int connected{0};
    for (int i{0}; i < edges.size(); i++)
    {
        int cost = edges[i][0];
        int par1 = find(edges[i][1]);
        int par2 = find(edges[i][2]);

        if (par1 != par2)
        {
            parent[par2] = par1;
            minCost += cost;
            connected++;
        }
        if (connected == n - 2)
        {
            cout << minCost;
            return 0;
        }
    }

    cout << "0";
}