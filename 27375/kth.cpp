#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int res;
pair<int, int> classes[6];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for (int i{0}; i < n; i++)
    {
        int w, s, e;
        cin >> w >> s >> e;
        classes[w] = {s, e};
    }

    // 시복도 : 2^20.
}