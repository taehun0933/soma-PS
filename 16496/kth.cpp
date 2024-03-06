#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string arr[1001];
string answer;

bool cmp(string &s1, string &s2)
{
    return s1 + s2 < s2 + s1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i{0}; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, cmp);
    reverse(arr, arr + n);

    for (int i{0}; i < n; i++)
        answer += arr[i];
    if (answer[0] == '0')
        answer = "0";

    cout << answer;
}