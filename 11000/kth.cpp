#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> classTimes;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--)
    {
        int s, t;
        cin >> s >> t;
        classTimes.push_back({s, t});
    }

    sort(classTimes.begin(), classTimes.end());
    pq.push(classTimes[0].second);
    int classNeed = 1;
    for (int i{1}; i < classTimes.size(); i++)
    {
        if (classTimes[i].first < pq.top())
        {
            // 겹침(클래스가 늘어남)
            pq.push(classTimes[i].second);
            classNeed++;
        }
        else
        {
            // 겹치지 않음(클래스가 늘어나지 않음)
            pq.pop();
            pq.push(classTimes[i].second);
        }
    }

    cout << classNeed;
}