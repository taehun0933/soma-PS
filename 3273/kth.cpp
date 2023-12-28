#include <iostream>
using namespace std;

int n;
int arr[100000];
int x;
int ssang;
bool gap[2000000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i{0}; i < n; i++)
        cin >> arr[i];
    cin >> x;

    for (int i{0}; i < n; i++)
    {
        if (x > arr[i])
        {
            if (gap[arr[i]])
                ssang++;
            gap[x - arr[i]] = true;
        }
    }

    cout << ssang;
}