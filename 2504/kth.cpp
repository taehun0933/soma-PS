#include <iostream>
#include <string>
#include <stack>
using namespace std;

string s;
stack<char> stc;
int res;
int addNum;

// minusNum 추가 설계. 가중치 계산을 위한 것.
// 언제 빼줄지, 언제 초기화할지 정하면 됨.
// 언제 빼는가? ->
// 언제 초기화하는가? ->

// ()[][] 문제X
// ( ) [ [ ] ] 문제X
// ( ( ) [ [ ] ] )

// 뒤에가 2개 연속 여는 괄호면 가중치? v

int minusNum;

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

            int topChar = stc.top();
            stc.pop();

            if (s[i - 1] == '(')
            {
                // 예외처리 체크 필요
                if (!stc.empty() && (s[i + 1] == '(' || s[i + 1] == '[') && (s[i + 2] == '(' || s[i + 2] == '['))
                {
                    // cout << "minus값 2 추가\n";
                    minusNum += 2;
                }
                addNum += 2;
            }
            else
                addNum *= 2;

            if (stc.empty())
            {
                res += addNum;
                if (topChar == '(')
                {
                    // cout << "(";
                    res -= minusNum * 2;
                }
                else if (topChar == '[')
                {
                    // cout << "[";
                    res -= minusNum * 3;
                }
                else
                {
                    // cout << "?";
                }
                // cout << "삭제 전 minusNum값 : " << minusNum << "\n";

                addNum = 0;
                minusNum = 0;
            }
            // (() ! [[]])
            // aN 2, res -2

            // 바로 이전문자열이 '('면 기존 결과에 2 더하기
        }
        else if (s[i] == ']')
        {
            if (stc.empty() || stc.top() != '[')
                getExit();

            int topChar = stc.top();
            stc.pop();

            // [[]] 그리고 res는 2

            // if (!stc.empty())
            //     res -= addNum;

            if (s[i - 1] == '[')
            {
                // 예외처리 체크 필요
                if (!stc.empty() && (s[i + 1] == '(' || s[i + 1] == '[') && (s[i + 2] == '(' || s[i + 2] == '['))
                {
                    // cout << "minus값 3 추가\n";
                    minusNum += 3;
                }
                addNum += 3;
            }

            else
            {
                minusNum *= 2;
                addNum *= 3;
            }

            if (stc.empty())
            {
                res += addNum;
                if (topChar == '(')
                {
                    // cout << "(";
                    res -= minusNum * 2;
                }
                else if (topChar == '[')
                {
                    // cout << "[";
                    res -= minusNum * 3;
                }
                else
                {
                }
                // cout << "?";

                addNum = 0;
                // cout << "삭제 전 minusNum값 : " << minusNum << "\n";
                minusNum = 0;
            }
        }
        else
        {
            stc.push(s[i]);

            // if (s[i] == '(' && (s[i + 1] == '(' || s[i + 1] == '['))
            //     res -= addNum * 2;
            // else if (s[i] == '[' && (s[i + 1] == '(' || s[i + 1] == '['))
            //     res -= addNum * 3;

            // if (i + 1 != s.length() && s[i] == '(' && s[i + 1] == '(')
            //     res -= addNum;
            // else if (i + 1 != s.length() && s[i] == '[' && s[i + 1] == '[')
            //     res -= addNum * 2;
        }
    }

    if (!stc.empty())
        getExit();
    cout << res;
}