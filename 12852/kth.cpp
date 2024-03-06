#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000001];
// 현재 위치에서 어디로 가야 최적인지를 나타내는 함수.
int pre[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{2}; i <= n; i++)
    {
        int minVal = arr[i - 1];
        pre[i] = i - 1;
        if (i % 3 == 0 && arr[i / 3] < minVal)
        {
            minVal = arr[i / 3];
            pre[i] = i / 3;
        }
        if (i % 2 == 0 && arr[i / 2] < minVal)
        {
            minVal = arr[i / 2];
            pre[i] = i / 2;
        }
        arr[i] = minVal + 1;
    }
    cout << arr[n] << '\n';

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    cout << n << " ";
    int cur{n};
    while (pre[cur] != 1)
    {
        cout << pre[cur] << " ";
        cur = pre[cur];
    }
    cout << 1;
}