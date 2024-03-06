#include <iostream>
#include <algorithm>
using namespace std;

#define X first
#define Y second

pair<pair<int, int>, pair<int, int>> schedules[100001];
int n;
int startMonth{3};
int startDay{1};
int flowerNum;
bool canComplete;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        schedules[i] = {{a, b}, {c, d}};

        if (c > 11)
            canComplete = 1;
    }

    if (!canComplete)
    {
        cout << 0;
        return 0;
    }

    sort(schedules, schedules + n);

    int idx{0};
    int maxMonth{0}, maxDay{0};
    int found{false};
    while (idx < n)
    {
        int month = schedules[idx].X.X;
        int day = schedules[idx].X.Y;

        if (month < startMonth || (month == startMonth && day <= startDay))
        {
            found = true;
            if (schedules[idx].Y.X > maxMonth || (schedules[idx].Y.X == maxMonth && schedules[idx].Y.Y > maxDay))
            {
                maxMonth = schedules[idx].Y.X;
                maxDay = schedules[idx].Y.Y;
            }
            idx++;
            if (idx == n)
            {
                flowerNum++;
                break;
            }
            continue;
        }

        if (!found)
        {
            cout << "0";
            return 0;
        }

        flowerNum++;
        startMonth = maxMonth;
        startDay = maxDay;
        if (startMonth > 11)
            break;
        maxMonth = 0;
        maxDay = 0;
        found = false;
    }

    cout << flowerNum;
}