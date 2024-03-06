#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100001];
int minVal{0x7fffffff};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i{0}; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    // 투 포인터 활용
    int st{0}, ed{0};
    while (ed <= n)
    {
        // a[ed] - a[st]가 m 이상일 경우 st를 1 증가
        // 아닐 경우 ed를 1 증가.
        if (a[ed] - a[st] >= m)
        {
            minVal = min(minVal, a[ed] - a[st]);
            st++;
        }
        else
            ed++;
    }
    cout << minVal;
}