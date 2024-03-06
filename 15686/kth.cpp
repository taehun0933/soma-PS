#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int board[51][51];
// m개를 뽑은 다음에 치킨거리 구하기
vector<pair<int, int>> chickenPos;
bool arr[51];
vector<pair<int, int>> housePos;
int minDis{0x7fffffff};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < n; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                chickenPos.push_back({i, j});
            if (board[i][j] == 1)
                housePos.push_back({i, j});
        }
    }

    for (int i{0}; i < chickenPos.size(); i++)
    {
        if (i < m)
            arr[i] = 0;
        else
            arr[i] = 1;
    }
    // nextPermutation 이용, m개 뽑기
    do
    {
        int dis[51][51];
        for (int i{0}; i < n; i++)
            for (int j{0}; j < n; j++)
                dis[i][j] = 1000;

        vector<pair<int, int>> selectedChickenPos;

        for (int i{0}; i < chickenPos.size(); i++)
        {
            if (arr[i] == 0)
            {
                // chickenPos[i]에 해당하는 좌표값을 선정
                selectedChickenPos.push_back(chickenPos[i]);
            }
        }

        for (auto p1 : selectedChickenPos)
            for (auto p2 : housePos)
                dis[p2.first][p2.second] = min(dis[p2.first][p2.second], abs(p1.first - p2.first) + abs(p1.second - p2.second));

        int sumDis{0};
        for (auto p : housePos)
            sumDis += dis[p.first][p.second];

        minDis = min(minDis, sumDis);

    } while (next_permutation(arr, arr + chickenPos.size()));

    cout << minDis;
}