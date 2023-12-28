#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int n;
stack<pair<int, int>> tops;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    // 저장 로직
    // stack에는 이전 입력값들 저장.
    // 현재 입력값이 stack의 top보다 크거나 같다면 stack을 pop하고 자기 자신을 push.
    //  -> 현재 stack의 top은 결국 자기 자신에 의해 막힐 것이기 때문.
    // 현재 입력값이 stack의 top보다 작다면, 현재 top을 출력하고 자기 자신을 push.

    for (int i{1}; i <= n; i++)
    {
        int height;
        cin >> height;

        if (tops.empty())
        {
            cout << "0 ";
            tops.push({height, i});
        }
        else
        {
            while (1)
            {
                if (tops.top().first <= height)
                {
                    tops.pop();
                    if (tops.empty())
                    {
                        cout << "0 ";
                        tops.push({height, i});
                        break;
                    }
                }
                else
                {
                    cout << tops.top().second << " ";
                    tops.push({height, i});
                    break;
                }
            }
        }
    }
}