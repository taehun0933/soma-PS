#include <iostream>
#include <algorithm>
using namespace std;

int n;
int weight[100005];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i{0}; i < n; i++)
        cin >> weight[i];

    sort(weight, weight + n);
    int curWeight{weight[n - 1]};
    for (int i{n - 2}; i >= 0; i--)
    {
        if (weight[i] * (n - i) > curWeight)
            curWeight = weight[i] * (n - i);
    }
    cout << curWeight;
}