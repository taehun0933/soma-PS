#include <iostream>
#include <stack>
#include <string>
using namespace std;

string s;
stack<char> stc;

int multiple = 1;
int res;

void getExit()
{
    cout << "0";
    exit(0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (int i{0}; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            if (stc.empty() || stc.top() != '(')
                getExit();

            if (s[i - 1] == '(')
            {
                stc.pop();
                res += multiple;
                multiple /= 2;
            }
            else
            {
                stc.pop();
                multiple /= 2;
            }
        }
        else if (s[i] == ']')
        {
            if (stc.empty() || stc.top() != '[')
                getExit();

            if (s[i - 1] == '[')
            {
                stc.pop();
                res += multiple;
                multiple /= 3;
            }
            else
            {
                stc.pop();
                multiple /= 3;
            }
        }
        else
        {
            stc.push(s[i]);
            if (s[i] == '(')
                multiple *= 2;
            else
                multiple *= 3;
        }
    }

    if (!stc.empty())
        getExit();

    cout << res;
}