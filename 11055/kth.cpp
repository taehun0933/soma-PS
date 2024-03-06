#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int N;
// DP[i] : 1부터 i번쨰 인덱스까지 가장 큰 증가하는 부분 수열의 합
// DP[i]는 i가 무조건 포함됨.
int DP[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i{1}; i <= N; i++)
        cin >> A[i];

    for (int i{1}; i <= N; i++)
    {
        DP[i] = A[i];
        for (int j{1}; j < i; j++)
            if (A[i] > A[j])
                // DP[i] = DP[j] + A[i]를 해 버리면
                // 기존 최댓값이 덮어씌워질 수도 있음.
                // ex) i가 4일 때 j가 3인 것보다 j가 2인 것이 더 클 수도.
                DP[i] = max(DP[i], DP[j] + A[i]);
    }

    cout << *max_element(DP + 1, DP + N + 1);
}