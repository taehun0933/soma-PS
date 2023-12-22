#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> pooth;
list<int> li;
int n, k;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i{1}; i <= n; i++)
        li.push_back(i);

    auto it = li.begin();

    while (li.size() != 0)
    {
        for (int i{0}; i < k - 1; i++)
        {
            it++;
            if (it == li.end())
                it = li.begin();
        }

        pooth.push_back(*it);
        it = li.erase(it);
    }

    cout << "<";
    for (int i{0}; i < pooth.size(); i++)
    {
        cout << pooth[i];
        if (i + 1 != pooth.size())
            cout << ", ";
    }
    cout << ">";
}
// int main(void)
// {
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n >> k;

//     for (int i{1}; i <= n; i++)
//         li.push_back(i);

//     auto it = li.begin();

//     while (li.size() != 0)
//     {
//         for (int i{0}; i < k; i++)
//         {
//             if (it == li.end())
//             {
//                 it = li.begin();
//                 it++;
//             }
//             else
//                 it++;
//         }

//         it--;
//         pooth.push_back(*it);
//         it = li.erase(it);
//     }

//     cout << "<";
//     for (int i{0}; i < pooth.size(); i++)
//     {
//         cout << pooth[i];
//         if (i + 1 != pooth.size())
//             cout << ", ";
//     }
//     cout << ">";
// }