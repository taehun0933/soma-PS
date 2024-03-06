#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    arr[2] = 1;
    arr[3] = 1;
    for (int i{4}; i <= N; i++)
    {
        if (i % 2 == 0 && i % 3 == 0)
            arr[i] = min({arr[i / 2], arr[i / 3], arr[i - 1]}) + 1;
        else if (i % 2 == 0)
            arr[i] = min({arr[i / 2], arr[i - 1]}) + 1;
        else if (i % 3 == 0)
            arr[i] = min({arr[i / 3], arr[i - 1]}) + 1;
        else
            arr[i] = arr[i - 1] + 1;
    }
    cout << arr[N];
}