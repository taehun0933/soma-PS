#include <iostream>
using namespace std;

int n;
int res;
int factos(int x)
{
    if (x == 1)
        return 1;
    return x * factos(x - 1);
}

// 1 * 2 * 3 * 4 * 5 * 6 * ..

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    cout << factos(100);
}
