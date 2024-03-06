#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];

bool BS(int val)
{
    int st{0}, ed{n - 1};
    int mid;

    while (st <= ed)
    {
        mid = (st + ed) / 2;
        if (arr[mid] == val)
            return 1;

        if (arr[mid] < val)
            st = mid + 1;
        else
            ed = mid - 1;
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    cin >> m;
    int x;
    for (int i{0}; i < m; i++)
    {
        cin >> x;
        cout << BS(x) << "\n";
    }
}
