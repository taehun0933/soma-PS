#include <iostream>
using namespace std;

int n, s;
int res;
int arr[21];

// k개까지의 수열의 합을 구하는
// idx번째를 선택하고 진행 or 선택 안하고 진행
// k번째 인덱스를 참고하여, 수열을 완성하는 함수.
void func(int k, int sum, int selected)
{
    // 현재 정답이 있는데, 다음 level에서 선택을 하지 않는다면 또 정답.
    // -> 다른 처리 필요.
    if (k == n)
    {
        if (selected > 0 && sum == s)
            res++;
        return;
    }

    // 선택 X
    func(k + 1, sum, selected);

    // 선택 O
    func(k + 1, sum + arr[k], selected + 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for (int i{0}; i < n; i++)
    {
        int x;
        cin >> x;
        arr[i] = x;
    }

    func(0, 0, 0);
    cout << res;
}