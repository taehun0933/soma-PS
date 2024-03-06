#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, X;
    cin >> N >> X;
    vector<int> arr(N);
    vector<int> result;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        if (arr[i] < X)
        {
            result.push_back(arr[i]);
        };
    };
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}