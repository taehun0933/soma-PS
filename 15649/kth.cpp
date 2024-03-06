#include <iostream>
#include <vector>
using namespace std;

int n, m;
int arr[10];
bool vis[10];

void func(int len)
{
    if (len == m)
    {
        for (int i{0}; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i{1}; i <= n; i++)
    {
        if (vis[i])
            continue;

        arr[len] = i;
        vis[i] = true;

        func(len + 1);

        vis[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    func(0);
}