#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        string s;
        getline(cin, s);

        if (s.length() == 1 && s[0] == '.')
            return 0;

        bool isBalanced{true};
        stack<char> stc;

        for (char c : s)
        {
            if (c == '(' || c == '[')
                stc.push(c);

            else if (c == ')')
            {
                if (stc.empty())
                {
                    isBalanced = false;
                    break;
                }
                else if (stc.top() == '(')
                    stc.pop();
                else
                {
                    isBalanced = false;
                    break;
                }
            }

            else if (c == ']')
            {
                if (stc.empty())
                {
                    isBalanced = false;
                    break;
                }
                else if (stc.top() == '[')
                    stc.pop();
                else
                {
                    isBalanced = false;
                    break;
                }
            }
        }

        if (!stc.empty())
            isBalanced = false;

        isBalanced ? cout << "yes\n" : cout << "no\n";
    }
}