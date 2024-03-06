#include <iostream>
#include <algorithm>
using namespace std;

// 실패

// DP[i] : 0번째부터 i번째 인덱스를 반드시 포함하는 상담 일정 중, 최대 이익.
// DP[i]를 채울 때, 최대 ~~
int N;
int T[1500051];
int P[1500051];

int DP[1500051];
// DP 입력 시, 언제까지 안되는지를 나타내는 값.
int until[1500051];
int maxP;

// 인덱스 말고, 날짜로 접근?

// i부터 끝까지의 합을 구하면?
// 만약 자기 자신을 선택했을 때, 못 쓰는 구간의 합과의 비교를 할 수 있다면?

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i{0}; i < N; i++)
        cin >> T[i] >> P[i];

    for (int i{0}; i < N; i++)
    {
        if (i + T[i] - 1 >= N)
            continue;

        DP[i] = P[i];
        until[i] = i + T[i] - 1;

        for (int j{0}; j < i; j++)
        {
            if (until[j] < i)
                DP[i] = max(DP[i], DP[j] + P[i]);
        }
    }

    cout << *max_element(DP, DP + N);
}