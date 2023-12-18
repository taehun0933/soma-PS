#include <iostream>
using namespace std;

int n, x;
int a[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    for (int i{0}; i < n; i++)
        cin >> a[i];

    for (int i{0}; i < n; i++)
        a[i] < x &&cout << a[i] << " ";
}