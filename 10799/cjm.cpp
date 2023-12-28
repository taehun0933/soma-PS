#include <iostream>
#include <stack>

using namespace std;

string a;
stack<char> s;
int piece; // 최종 출력물
int stick[500000];
int s_num;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a;
    // int oneL;

    for (int i = 0; i < a.length(); i++)
    {
        char p = a[i];
        if (p == '(')
        {
            if (s.top() == '(')
            {
                int size = s.size();
                s_num++;
            }
            s.push(p);
        }
        else
        { // p == ')'
            if (s.top() == '(')
            { // 레이저인 경우
                // oneL++;
                s.push(p);

                for (int j = 0; j < s_num; j++)
                { // 현재 존재하는 쇠막대기에 모두 레이저개수를 +1해줌
                    stick[j] += 1;
                }
            }
            else
            { // 하나의 쇠막대기 clear하는 경우
                int w = stick[s_num] * 2 + 1;

                while (w--)
                {
                    s.pop(); // 하나의 쇠막대기 clear
                }
                // piece += oneL;
                piece += stick[s_num] + 1;

                stick[s_num] = 0;
                s_num--;
            }
        }
    }

    cout << piece;
}