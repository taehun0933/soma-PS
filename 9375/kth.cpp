#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        vector<string> clothes;

        string clothName, clothKind;
        for (int i{0}; i < n; i++)
        {
            cin >> clothName >> clothKind;
            clothes.push_back(clothKind);
        }

        sort(clothes.begin(), clothes.end());

        // clothes를 돌며 각 종류별로 옷이 몇개인지 판단 후 vec에 push.
        vector<int> vec;
        int clothNum{1};
        for (int i{1}; i < clothes.size(); i++)
        {
            if (clothes[i] != clothes[i - 1])
            {
                vec.push_back(clothNum);
                clothNum = 1;
            }
            else
                clothNum++;
        }
        vec.push_back(clothNum);

        int sum{1};
        for (int i{0}; i < vec.size(); i++)
            sum *= (vec[i] + 1);

        cout << sum - 1 << '\n';
    }
}