#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[100001];
int minLen{0x7fffffff};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    for (int i{0}; i < n; i++)
        cin >> arr[i];

    // 투 포인터 이용
    // 값이 S 이상이라면 st 증가, 미만이라면 ed 증가.
    int st{0}, ed{0};
    int sum{0};
    int len{0};
    // st부터 ed-1까지의 합을 구하기.
    while (ed <= n)
    {
        if (sum >= s)
        {
            minLen = min(minLen, len);
            sum -= arr[st];
            len--;
            st++;
        }
        else
        {
            sum += arr[ed];
            len++;
            ed++;
        }
    }

    if (minLen == 0x7fffffff)
        cout << 0;
    else
        cout << minLen;
}