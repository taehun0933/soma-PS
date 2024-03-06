#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
bool knowTruth[51];
bool cannotLieParent[51];
int parent[51];
vector<vector<int>> partyList;

int find(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

// 언젠가 진실을 알게 될 수도 있는 그룹 | 진실을 끝까지 모르는 그룹으로 나눈 후
// 파티에 참석하는 인원 중 한 명이라도 전자에 포함될 경우 진실을 말해야 함.

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for (int i{1}; i <= n; i++)
        parent[i] = i;

    while (k--)
    {
        int x;
        cin >> x;
        knowTruth[x] = 1;
    }

    for (int i{0}; i < m; i++)
    {
        int x;
        cin >> x;
        vector<int> party;
        while (x--)
        {
            int y;
            cin >> y;
            party.push_back(y);
        }
        partyList.push_back(party);
    }

    // for (auto v : partyList)
    // {
    //     // int par1 = find(v[0]);
    //     // for (int i{1}; i < v.size(); i++)
    //     // {
    //     //     int par2 = find(v[i]);
    //     //     // parent[par1] = par2;
    //     //     parent[par2] = par1;
    //     // }
    // }

    for (auto v : partyList)
    {
        for (int i{0}; i < v.size() - 1; i++)
        {
            int par1 = find(v[i]);
            int par2 = find(v[i + 1]);

            parent[par2] = par1;
        }
    }

    // 초창기에 전달받았던, 진실을 아는 사람이 있다면
    // 해당하는 parent값을 인덱스로 접근, cannotLieParent 값 변경
    for (int i{1}; i <= n; i++)
    {
        if (knowTruth[i])
            cannotLieParent[find(i)] = 1;
    }

    int canLie = m;
    for (auto v : partyList)
    {
        for (auto i : v)
        {
            if (cannotLieParent[find(i)])
            {
                canLie--;
                break;
            }
        }
    }
    cout << canLie;
}