#include <iostream>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int res;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    auto it = v.begin();
    while (!v.empty() && *it < 0)
    {
        if (v.size() <= 1 || *(it + 1) > 0)
            break;

        int mult = (*it) * (*(it + 1));
        res += mult;

        it = v.erase(it);
        it = v.erase(it);
    }

    it = v.end() - 1;

    while (!v.empty() && *it > 0)
    {
        if (v.size() <= 1 || *(it - 1) <= 0)
            break;

        if (*(it - 1) == 1)
            break;
        int mult = (*it) * (*(it - 1));
        res += mult;

        it = v.erase(it);
        it--;
        it = v.erase(it);
        it--;
    }

    for (auto i : v)
        res += i;

    cout << res;
}