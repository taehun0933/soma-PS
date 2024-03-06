#include <iostream>
using namespace std;

int arr[11];
int T;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for (int i{4}; i <= 10; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

    while (T--)
    {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
}