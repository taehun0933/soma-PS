#include <iostream>
#include <queue>
#include <string>
using namespace std;

int a, b;
queue<pair<int, int>> Q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    Q.push({a, 1});

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (cur.first == b)
        {
            cout << cur.second;
            return 0;
        }
        bool canGo{false};

        if (cur.first * 2 <= b)
            Q.push({cur.first * 2, cur.second + 1});

        string s = to_string(cur.first);
        s += '1';
        if (stoll(s) <= b)
            Q.push({stoll(s), cur.second + 1});
    }

    cout << "-1";
    return 0;
}