#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> Q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s == "push")
        {
            int x;
            cin >> x;
            Q.push(x);
        }
        else if (s == "pop")
        {
            if (Q.empty())
                cout << "-1\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (s == "size")
            cout << Q.size() << "\n";
        else if (s == "empty")
            cout << Q.empty() << "\n";
        else if (s == "front")
        {
            if (Q.empty())
                cout << "-1\n";
            else
                cout << Q.front() << "\n";
        }
        else if (s == "back")
        {
            if (Q.empty())
                cout << "-1\n";
            else
                cout << Q.back() << "\n";
        }
    }
}