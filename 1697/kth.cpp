#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;

int board_dis[200001];
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(board_dis, board_dis + 200001, -1);
    cin >> n >> k;
    board_dis[n] = 0;
    Q.push(n);

    while (!Q.empty())
    {
        int cur = Q.front();
        if (cur == k)
            break;
        Q.pop();

        for (auto i : {cur - 1, cur + 1, cur * 2})
        {
            if (i < 0 || i > 100000 || board_dis[i] != -1)
                continue;

            Q.push(i);
            board_dis[i] = board_dis[cur] + 1;
        }
    }

    cout << board_dis[k];
}