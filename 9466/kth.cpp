#include <iostream>
#include <queue>
using namespace std;

int t;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 특정 번호에서 시작해서 자기 자신에게 돌아온다면 팀 구성, 아니라면 팀매칭 실패
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int choice[100001];
        bool vis[100001];
        bool isTeamMember[100001];

        for (int i{1}; i <= n; i++)
        {
            cin >> choice[i];
            vis[i] = 0;
            isTeamMember[i] = 0;
        }

        for (int i{1}; i <= n; i++)
        {
            if (!vis[i])
            {
                int startPos = i;
                queue<int> Q;
                // 이동 경로를 담은 큐
                queue<int> tmpQ;
                Q.push(i);
                tmpQ.push(i);
                vis[i] = 1;
                while (!Q.empty())
                {
                    int cur = Q.front();
                    Q.pop();

                    int nPos = choice[cur];

                    if (choice[cur] == cur)
                    {
                        isTeamMember[cur] = 1;
                        break;
                    }

                    if (vis[nPos])
                    {
                        // 사이클 찾음. 현재 tmpQ에 담긴 인원들 모두 매칭된 팀원으로 추가
                        if (nPos == i)
                        {
                            while (!tmpQ.empty())
                            {
                                int tmpM = tmpQ.front();
                                tmpQ.pop();
                                isTeamMember[tmpM] = 1;
                            }
                            break;
                        }
                        else
                        // 중간에 사이클 형성, tmpQ의 front부터 pop하며 nPos가 나올 때까지 pop
                        // 이후 매칭된 팀원에 남은 인원들 추가
                        {
                            while (!tmpQ.empty() && tmpQ.front() != nPos)
                                tmpQ.pop();
                            while (!tmpQ.empty())
                            {
                                int tmpM = tmpQ.front();
                                tmpQ.pop();
                                isTeamMember[tmpM] = 1;
                            }
                            break;
                        }
                    }

                    vis[nPos] = 1;

                    Q.push(nPos);
                    tmpQ.push(nPos);
                }
            }
        }

        int res{0};
        for (int i{1}; i <= n; i++)
            if (!isTeamMember[i])
                res++;
        cout << res << "\n";
    }
}