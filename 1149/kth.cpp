#include <iostream>
#include <algorithm>
using namespace std;

int numOfHouse;
// 이중배열 순서대로 R,G,B를 칠하는데 필요한 값
int cost[1001][3];
int costNeed[1001][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> numOfHouse;

    for (int i{1}; i <= numOfHouse; i++)
        for (int j{0}; j < 3; j++)
            cin >> cost[i][j];

    for (int i{0}; i < 3; i++)
        costNeed[1][i] = cost[1][i];

    for (int i{2}; i <= numOfHouse; i++)
    {
        costNeed[i][0] = min(costNeed[i - 1][1], costNeed[i - 1][2]) + cost[i][0];
        costNeed[i][1] = min(costNeed[i - 1][0], costNeed[i - 1][2]) + cost[i][1];
        costNeed[i][2] = min(costNeed[i - 1][0], costNeed[i - 1][1]) + cost[i][2];
    }

    cout << min({costNeed[numOfHouse][0], costNeed[numOfHouse][1], costNeed[numOfHouse][2]});
}