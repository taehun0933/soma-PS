#include <iostream>
#include <algorithm>
using namespace std;

int A[51], B[51];
int n;
int res;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i{0}; i < n; i++)
        cin >> A[i];
    for (int i{0}; i < n; i++)
        cin >> B[i];

    sort(A, A + n);
    sort(B, B + n);

    for (int i{0}; i < n; i++)
        res += A[i] * B[n - i - 1];

    cout << res;
}