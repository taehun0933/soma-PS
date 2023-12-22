#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

int k, sum;
stack<int> stc;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;

        if (n == 0)
            stc.pop();
        else
            stc.push(n);
    }

    while (!stc.empty())
    {
        sum += stc.top();
        stc.pop();
    }

    cout << sum;
}