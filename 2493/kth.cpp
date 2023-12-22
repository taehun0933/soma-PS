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

    // O(N) 이하의 시간복잡도 필요.
    // 배열 & 이중for문? => O(N^2), 시간초과

    // stack 활용 설계
    // for문으로 초기 반복 횟수 설정 : n만큼 하면 됨.
    // 맨 마지막 삽입된 원소부터 시작하여 pop & push, 한번 수행할 때 해당 원소가 제거되면 됨.
    // => 결국엔 O(N^2)인데?

    // 입력을 받는 동시에 무언가 처리?
    // stack에다가 저장을 하자.

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