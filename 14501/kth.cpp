#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[21];
int P[21];
int maxP;

void func(int k, int sumP)
{
    if (k == N)
    {
        maxP = max(maxP, sumP);
        return;
    }

    if (k + T[k] <= N)
        func(k + T[k], sumP + P[k]);

    func(k + 1, sumP);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i{0}; i < N; i++)
        cin >> T[i] >> P[i];

    func(0, 0);
    cout << maxP;
}
