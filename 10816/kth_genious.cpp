#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cards[20000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int x;
    while (n--)
    {
        cin >> x;
        cards[x + 10000000]++;
    }

    cin >> m;
    while (m--)
    {
        cin >> x;
        cout << cards[x + 10000000] << " ";
    }
}