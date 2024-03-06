#include <iostream>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int n, k;
int dis[200001];
int from[200001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    queue<int> Q;
    fill(dis, dis + 200001, -1);
    Q.push(n);
    dis[n] = 0;

    // 이러면 10의 from을 5로, 9의 from을 10으로 ...
    while (!Q.empty())
    {
        int cur = Q.front();
        if (cur == k)
        {
            cout << dis[k] << '\n';
            int cursor = k;
            stack<int> stc;
            while (cursor != n)
            {
                stc.push(cursor);
                cursor = from[cursor];
            }
            stc.push(n);
            while (!stc.empty())
            {
                cout << stc.top() << " ";
                stc.pop();
            }
            return 0;
        }
        Q.pop();

        for (int nxt : {cur - 1, cur + 1, cur * 2})
        {
            if (nxt < 0 || nxt >= 200000)
                continue;
            if (dis[nxt] != -1)
                continue;

            Q.push(nxt);
            dis[nxt] = dis[cur] + 1;
            from[nxt] = cur;
        }
    }
}