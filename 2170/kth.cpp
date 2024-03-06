#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int n;
int len;
pair<int, int> pos[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pos[i] = {x, y};
    }

    sort(pos, pos + n);

    len = pos[0].Y - pos[0].X;
    int curLeft = pos[0].X;
    int curRight = pos[0].Y;
    for (int i{1}; i < n; i++)
    {
        if (curRight >= pos[i].Y)
            continue;

        if (curRight > pos[i].X)
            len -= (curRight - pos[i].X);
        len += (pos[i].Y - pos[i].X);

        curLeft = pos[i].X;
        curRight = pos[i].Y;
    }

    cout << len;
}