#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dis[20001];
vector<int> adj[20001];
queue<int> Q;
int v, e, k;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e;
    cin >> k;
    Q.push(k);
}