#include <iostream>
#include <algorithm>
using namespace std;

int t;
int costs[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i{0}; i < n; i++)
            cin >> costs[i];

        int maxVal = costs[n - 1];
        long long total{0};
        for (int i{n - 2}; i >= 0; i--)
        {
            if (maxVal < costs[i])
                maxVal = costs[i];
            else
                total += maxVal - costs[i];
        }
        cout << total << "\n";
    }
}

// 기존 풀이
// #include <iostream>
// #include <algorithm>
// using namespace std;

// int t;
// int costs[1000001];
// // 주가,인덱스 순
// pair<int, int> costInfos[1000001];

// bool cmp(pair<int, int> &p1, pair<int, int> &p2)
// {
//     if (p1.first == p2.first)
//         return p1.second < p2.second;

//     return p1.first > p2.first;
// }

// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     // 최대 이익
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         for (int i{0}; i < n; i++)
//         {
//             cin >> costs[i];
//             costInfos[i] = {costs[i], i};
//         }
//         sort(costInfos, costInfos + n, cmp);

//         // 엣지케이스(시간초과) 처리
//         if (costInfos[0].second == 0)
//         {
//             cout << "0\n";
//             continue;
//         }

//         int idx{-1};
//         // 멈추어야 할 인덱스
//         vector<int> v;

//         for (int i{0}; i < n; i++)
//         {
//             int curIdx = costInfos[i].second;
//             if (curIdx > idx)
//             {
//                 v.push_back(curIdx);
//                 idx = curIdx;
//             }
//         }

//         // 최종 가격
//         long long total = 0;
//         // 총 주식 매수
//         int costCount{0};
//         for (int i{0}; i < n; i++)
//         {
//             int curCost = costs[i];
//             if (i == v.front())
//             {
//                 // 모았던 주식을 모두 팖
//                 total += costCount * curCost;
//                 costCount = 0;
//                 v.erase(v.begin());
//             }
//             else
//             {
//                 // 주식을 삼
//                 total -= curCost;
//                 costCount++;
//             }
//         }
//         cout << total << "\n";
//     }
// }
