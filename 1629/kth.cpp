#include <iostream>

using namespace std;
#define ll long long

int a, b, c;

// A^BmodC 함수.
// func(1)을 구할 수 있다.
// XmodY * XmodY == (X^2modY)modY이므로
// -> func(k)를 알면 func(2k), func(2k+1)을 O(1)에 구할 수 있다.

ll func(int a, int b, int c)
{
    if (b == 1)
        return a % c;

    // A^BmodC == (A^(B/2)modC * A^(B/2)modC)modC
    ll res = func(a, b / 2, c) % c;
    if (b % 2 == 0)
        return (res * res) % c;
    else
        return (res * res % c * a) % c;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << func(a, b, c);
}