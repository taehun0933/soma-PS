#include <iostream>
#include <stack>
using namespace std;

stack<int> stc;
int n;

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
            stc.push(x);
        }
        if (s == "pop")
        {
            if (stc.empty())
                cout << "-1\n";
            else
            {
                cout << stc.top() << "\n";
                stc.pop();
            }
        }
        if (s == "size")
            cout << stc.size() << "\n";
        if (s == "empty")
            cout << stc.empty() << "\n";
        if (s == "top")
        {
            if (stc.empty())
                cout << "-1\n";
            else
                cout << stc.top() << "\n";
        }
    }
}