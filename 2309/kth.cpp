#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int nanzang[9];
int res[7];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i{0}; i < 9; i++)
        cin >> nanzang[i];

    for (int i{0}; i < 9; i++)
    {
        for (int j{0}; j < 9 && j != i; j++)
        {
            vector<int> v;
            int tmp_res{0};

            for (int k{0}; k < 9; k++)
            {
                if (k != i && k != j)
                    v.push_back(nanzang[k]);
            }

            for (auto i : v)
                tmp_res += i;

            if (tmp_res == 100)
            {
                sort(v.begin(), v.end());
                for (auto i : v)
                    cout << i << "\n";

                return 0;
            }
        }
    }
}