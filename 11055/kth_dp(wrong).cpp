#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001];
int maxSum;

// k번쨰 인덱스를 참고하는 함수
void func(int k, int cur, int sum)
{
    if (k == N)
    {
        maxSum = max(maxSum, sum);
        return;
    }

    if (arr[k] > cur)
        func(k + 1, arr[k], sum + arr[k]);
    func(k + 1, cur, sum);
}

// 백트래킹?

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i{0}; i < N; i++)
        cin >> arr[i];

    func(0, 0, 0);
    cout << maxSum;
}