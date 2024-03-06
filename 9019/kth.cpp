#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

#define vis first
#define cmd second

int T;
int A, B;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        cin >> A >> B;

        int res{0};
        pair<bool, string> visCmd[10000];

        queue<int> Q;

        Q.push(A);
        visCmd[A].vis = 1;

        while (!Q.empty())
        {
            if (Q.front() == B)
            {
                cout << visCmd[B].cmd;
                cout << "\n";
                break;
            }

            int cur = Q.front();
            Q.pop();

            // D
            int nD = (cur * 2) % 10000;
            if (!visCmd[nD].vis)
            {
                Q.push(nD);
                visCmd[nD].cmd = visCmd[cur].cmd + 'D';
                visCmd[nD].vis = 1;
            }

            // S
            int nS = (cur == 0) ? 9999 : cur - 1;
            if (!visCmd[nS].vis)
            {
                Q.push(nS);
                visCmd[nS].cmd = visCmd[cur].cmd + 'S';
                visCmd[nS].vis = 1;
            }

            // L
            int nL;
            if (cur < 1000)
                nL = cur * 10;
            else
                nL = (cur % 1000) * 10 + (cur / 1000);

            if (!visCmd[nL].vis)
            {
                Q.push(nL);
                visCmd[nL].cmd = visCmd[cur].cmd + 'L';
                visCmd[nL].vis = 1;
            }

            int nR = (cur / 10) + (1000 * (cur % 10));

            if (!visCmd[nR].vis)
            {
                Q.push(nR);
                visCmd[nR].cmd = visCmd[cur].cmd + 'R';
                visCmd[nR].vis = 1;
            }
        }
    }
}