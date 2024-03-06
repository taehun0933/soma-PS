#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int U[1001];
int n;
vector<int> pairSum;
int maxVal;

// 두개만 정하고 나머지 값을 find?
//  x+y+z = k <-> x+y = k-z 이용, U를 돌면서 k-z를 구하고(이중for문), 해당 값이 x+y인지
//  binary search를 이용해서 구하기.
//  -> 시간복잡도 : O(N^2log(N^2)) == O(N^2 * 2logN) == O(N^2logN)
//  -> 이를 위해, x+y를 미리 구해 놓자.

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
        cin >> U[i];

    sort(U, U + n);
    for (int i{0}; i < n; i++)
        for (int j{i}; j < n; j++)
            pairSum.push_back(U[i] + U[j]);

    // 정렬 주의!
    sort(pairSum.begin(), pairSum.end());

    for (int i{0}; i < n; i++)
        for (int j{0}; j < n; j++)
        {
            int z = U[i];
            int k = U[j];

            int findVal = k - z;
            if (findVal > 0 && binary_search(pairSum.begin(), pairSum.end(), findVal))
                maxVal = max(maxVal, k);
        }
    cout << maxVal;
}