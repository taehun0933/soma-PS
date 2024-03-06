#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
string s;
string arr[100001];

int main(void)
{
    cin >> t;
    while (t--)
    {
        cin >> n;

        for (int i{0}; i < n; i++)
            cin >> arr[i];

        if (n > 32)
        {
            cout << "0\n";
            continue;
        }

        int min{8};
        for (int i{0}; i < n; i++)
            for (int j{i + 1}; j < n; j++)
            {
                for (int k{j + 1}; k < n; k++)
                {
                    string first = arr[i];
                    string second = arr[j];
                    string third = arr[k];

                    int gap{0};

                    for (int a{0}; a < 4; a++)
                    {
                        if (first[a] != second[a])
                            gap++;
                        if (second[a] != third[a])
                            gap++;
                        if (third[a] != first[a])
                            gap++;
                    }

                    if (min > gap)
                        min = gap;
                }
            }
        cout << min << "\n";
    }
}