#include <iostream>
#include <stack>

using namespace std;

stack<char> stc;
stack<int> expectingIdxStc;
string s;
string explode;

int main(void)
{
    cin >> s >> explode;
    expectingIdxStc.push(0);

    for (int i{0}; i < s.length(); i++)
    {
        stc.push(s[i]);
        int &expectIdx = expectingIdxStc.top();
        if (stc.top() == explode[expectIdx])
        {
            expectIdx++;
            if (expectIdx == explode.length())
            {
                // 해당 explode.length()만큼 폭발
                for (int j{0}; j < explode.length(); j++)
                    stc.pop();

                expectingIdxStc.pop();
                // 비어있으면 추가
                if (expectingIdxStc.empty())
                    expectingIdxStc.push(0);
            }
        }
        else
        {
            // 앞으로 들어올 문자열이 폭발 문자열일 경우
            // 그 이후의 문자열들과 현재 문자열이 합쳐져서 폭발 문자열이 될 수도 있음
            if (stc.top() == explode[0])
            {
                expectingIdxStc.push(1);
            }
            else
            {
                while (!expectingIdxStc.empty())
                    expectingIdxStc.pop();
                expectingIdxStc.push(0);
            }
        }
    }

    string ans = "";
    if (stc.empty())
    {
        cout << "FRULA";
        return 0;
    }
    while (!stc.empty())
    {
        ans.push_back(stc.top());
        stc.pop();
    }

    for (int i = ans.length() - 1; i >= 0; i--)
        cout << ans[i];
}