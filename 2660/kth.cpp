#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
// 하나씩 BFS 돌면서, dist가 가장 큰 것으로 점수 결정
// BFS 한번 돌면, 점수랑 번호 vector에 push
// 모두가 서로 알 수 있음. 이에 대한 예외처리 안해줘도 됨
vector<int> adj[51];
vector<pair<int, int>> scoreAndPerson;

void BFS(int personNum)
{
    int tmp_dis[51];
    for (int i{1}; i <= n; i++)
    {
        if (i == personNum)
            tmp_dis[i] = 0;
        else
            tmp_dis[i] = -1;
    }

    queue<int> Q;
    Q.push(personNum);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (auto nxt : adj[cur])
        {
            if (tmp_dis[nxt] != -1)
                continue;
            Q.push(nxt);
            tmp_dis[nxt] = tmp_dis[cur] + 1;
        }
    }
    int maxDis = *max_element(tmp_dis + 1, tmp_dis + 1 + n);
    scoreAndPerson.push_back({maxDis, personNum});
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int a, b;
    while (cin >> a >> b)
    {
        if (a == -1 && b == -1)
            break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i{1}; i <= n; i++)
        BFS(i);

    sort(scoreAndPerson.begin(), scoreAndPerson.end());
    vector<int> kingList;
    int minScore = scoreAndPerson[0].first;
    for (auto p : scoreAndPerson)
        if (p.first == minScore)
            kingList.push_back(p.second);

    cout << minScore << " " << kingList.size() << "\n";
    for (auto i : kingList)
        cout << i << " ";
}