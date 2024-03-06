#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> meetings[100001];
int meetingNum;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
    {
        cin >> meetings[i].second;
        cin >> meetings[i].first;
    }
    sort(meetings, meetings + n);

    // meetings의 첫 번째는 끝나는 시간, 두 번째는 시작 시간임.
    // 끝나는 시간이 가장 빠른 것부터.
    int minTime{0};
    for (int i{0}; i < n; i++)
    {
        if (meetings[i].second < minTime)
            continue;

        minTime = meetings[i].first;
        meetingNum++;
    }

    cout << meetingNum;
}