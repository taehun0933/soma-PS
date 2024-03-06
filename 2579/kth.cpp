#include <iostream>
#include <algorithm>
using namespace std;

int stairScore[301];
int numOfStairs;
// 연속해서 몇 개의 계단을 밟은 상태의, 몇 번째 계단에 존재할 때의 최대 점수
int topStairScore[301][3];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> numOfStairs;
    for (int i{1}; i <= numOfStairs; i++)
        cin >> stairScore[i];

    // 이전 계단, 혹은 두 계단 이전을 통해 현재 값 구성
    topStairScore[1][1] = stairScore[1];
    topStairScore[2][1] = stairScore[2];
    topStairScore[2][2] = stairScore[1] + stairScore[2];

    for (int i{3}; i <= numOfStairs; i++)
    {
        topStairScore[i][1] = max(topStairScore[i - 2][1], topStairScore[i - 2][2]) + stairScore[i];
        topStairScore[i][2] = topStairScore[i - 1][1] + stairScore[i];
    }
    cout << max(topStairScore[numOfStairs][1], topStairScore[numOfStairs][2]);
}