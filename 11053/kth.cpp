#include <iostream>
#include <algorithm>
using namespace std;

// DP[i] : i번째 원소를 포함하는 증가 부분수열의 최대 길이
int DP[1001];
int arr[1001];
int N;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i{0}; i < N; i++)
        cin >> arr[i];

    for (int i{0}; i < N; i++)
    {
        DP[i] = 1;
        for (int j{0}; j < i; j++)
            if (arr[i] > arr[j])
                DP[i] = max(DP[i], DP[j] + 1);
    }
    cout << *max_element(DP, DP + N);
}