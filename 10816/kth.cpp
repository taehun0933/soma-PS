#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int cards[500001];

int BS_count(int findVal)
{
    int st{0}, ed{n - 1};
    int mid;

    while (st <= ed)
    {
        mid = (st + ed) / 2;

        if (cards[mid] == findVal)
        {
            int found{1};
            int idxLeft = mid - 1;
            int idxRight = mid + 1;

            while (idxLeft >= 0 && cards[idxLeft] == findVal)
            {
                found++;
                idxLeft--;
            }
            while (idxRight < n && cards[idxRight] == findVal)
            {
                found++;
                idxRight++;
            }
            return found;
        }

        if (cards[mid] > findVal)
            ed = mid - 1;
        else
            st = mid + 1;
    }
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
        cin >> cards[i];

    sort(cards, cards + n);

    cin >> m;
    int x;
    while (m--)
    {
        cin >> x;
        cout << BS_count(x) << " ";
    }
}
