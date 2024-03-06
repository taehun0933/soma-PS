#include <iostream>
using namespace std;

int t;
long long DP[102];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;

    for (int i{4}; i <= 100; i++)
        DP[i] = DP[i - 3] + DP[i - 2];

    while (t--)
    {
        int n;
        cin >> n;
        cout << DP[n] << "\n";
    }
}