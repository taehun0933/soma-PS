#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DP[i] : i번째 수열을 포함하는, 증가하는 부분 수열의 최대 길이를 가지게 하는 배열
vector<int> DP[1001];
int n;
int arr[1001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{1}; i <= n; i++)
        cin >> arr[i];

    DP[1].push_back(arr[1]);

    // DP[i] 결정.
    for (int i{2}; i <= n; i++)
    {
        int maxSizeIdx{-1};
        int maxSize{0};

        for (int j{1}; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                if (DP[j].size() > maxSize)
                {
                    maxSize = DP[j].size();
                    maxSizeIdx = j;
                }
            }
        }
        if (maxSizeIdx != -1)
            for (auto num : DP[maxSizeIdx])
                DP[i].push_back(num);

        DP[i].push_back(arr[i]);
    }

    int maxSize{0};
    int maxSizeIdx{-1};

    for (int i{1}; i <= n; i++)
    {
        if (DP[i].size() > maxSize)
        {
            maxSize = DP[i].size();
            maxSizeIdx = i;
        }
    }

    cout << maxSize << "\n";
    for (auto num : DP[maxSizeIdx])
        cout << num << " ";
}