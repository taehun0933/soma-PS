#include <iostream>
using namespace std;

int k, n;
int lan[10001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> n;
    for (int i{0}; i < k; i++)
        cin >> lan[i];

    // 입력받은 랜선값 중 최대를 기점, binary_search.
    // mid값이 왼쪽으로 갈수록 만들 수 있는 수가 커지고, 오른쪽으로 갈 수록 작아짐.
    // mid값을 통해 만들수 있는 수가 N과 동일할 경우, 오른쪽으로 가면서 최댓값 찾기.

    // 값 찾는 것 자체는 O(NlogN) + O(N^2)

    long long start{1}, end{0x7fffffff}; // 2^31-1
    long long mid;
    while (start <= end)
    {
        mid = (start + end) / 2;

        int lanNum{0};
        for (int i{0}; i < k; i++)
            lanNum += (lan[i] / mid);

        if (lanNum >= n)
            start = mid + 1;
        else
            end = mid - 1;
    }
    cout << end;
}