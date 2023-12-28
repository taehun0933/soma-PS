#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> stc;
string s;
int numOfStick;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (int i{0}; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            if (s[i - 1] == '(')
            {
                // 레이저 쌍. 왼쪽 괄호 개수 파악.
                stc.pop();
                numOfStick += stc.size();
            }
            else
            {
                numOfStick++;
                stc.pop();
            }
        }
        else
            stc.push(s[i]);
    }

    cout << numOfStick;
}