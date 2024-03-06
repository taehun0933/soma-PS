#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
int cards[500001];
vector<pair<int, int>> cards_vec;

int BS_count(int findVal)
{
    int st{0}, ed{static_cast<int>(cards_vec.size()) - 1};
    int mid;

    while (st <= ed)
    {
        mid = (st + ed) / 2;

        if (cards_vec[mid].first == findVal)
            return cards_vec[mid].second;

        if (cards_vec[mid].first > findVal)
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
    // 첫번째는 숫자, 두번째는 해당 숫자 개수
    for (int i{0}; i < n; i++)
    {
        int x = cards[i];
        int cardCount{1};
        i++;
        while (cards[i] == x && i < n)
        {
            cardCount++;
            i++;
        }
        cards_vec.push_back({x, cardCount});
        i--;
    }

    cin >> m;
    int x;
    while (m--)
    {
        cin >> x;
        cout << BS_count(x) << " ";
    }
}
