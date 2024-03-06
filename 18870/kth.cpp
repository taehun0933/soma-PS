#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int x[1000001];
vector<int> uni;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int val;
    for (int i{0}; i < n; i++)
    {
        cin >> val;
        x[i] = val;
        uni.push_back(val);
    }

    sort(uni.begin(), uni.end());

    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (int i{0}; i < n; i++)
        cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << " ";
}