#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
// arr[i] : 1부터 i번째까지의 누적합을 담은 배열.
// 추후에 arr[b] - arr[a]의 형태로 값을 구할 것인데, 이 때 arr[a]가 0,
//  즉 첫 번째 항부터 마지막 항까지의 합이 정답이 될 수도 있으므로, arr[0]은 0값으로 비워 둔다.
int arr[100001];
int minLen{0x7fffffff};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    int x;
    for (int i{1}; i <= n; i++)
    {
        cin >> x;
        if (i == 1)
            arr[i] = x;
        else
            arr[i] = arr[i - 1] + x;
    }

    for (int i{0}; i < n; i++)
    {
        // arr[x] - arr[i] >= s를 만족해야 함
        // => arr[x] >= s + arr[i], lower_bound 이용
        int findVal = arr[i] + s;
        int findIdx = lower_bound(arr + 1, arr + n + 1, findVal) - arr;
        if (findIdx == n + 1)
            continue;
        minLen = min(minLen, findIdx - i);
    }

    if (minLen == 0x7fffffff)
        cout << 0;
    else
        cout << minLen;
}