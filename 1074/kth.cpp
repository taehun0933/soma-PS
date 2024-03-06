#include <iostream>
using namespace std;

int N, r, c;
int visited;

// n은 현재 크기.
void func(int n, int _r, int _c)
{
    if (n == 1)
    {
        if (r == _r && c == _c)
        {
            cout << visited;
            exit(0);
        }
        return;
    }

    // 1 ~ 4 사분면 돌기.
    // 시간초과 뜸. 몇사분면에 있는지 파악해서 바로 들어가는 게 좋을 듯?

    int newR = _r + (n / 2);
    int newC = _c + (n / 2);

    if (r < newR && c < newC)
        func(n / 2, _r, _c);
    else if (r < newR && c >= newC)
    {
        visited += n * n / 4;
        func(n / 2, _r, _c + (n / 2));
    }
    else if (r >= newR && c < newC)
    {
        visited += n * n / 4 * 2;
        func(n / 2, _r + (n / 2), _c);
    }
    else
    {
        visited += n * n / 4 * 3;
        func(n / 2, _r + (n / 2), _c + (n / 2));
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> r >> c;

    // 2^N * 2^N 크기.
    func((1 << N), 0, 0);
}