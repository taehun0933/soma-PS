#include <iostream>
using namespace std;

int n;
int possible;
int put[15][15];
// 시간복잡도를 최적화하기 위해, 해당 열에 이미 퀸이 존재하는지에 대한 여부의 변수를 추가로 할당.
bool columnUsed[15];

// 퀸을 놓고 제거할 때 좌하단, 우하단 방향으로 배치 불가 공간을 확장하는 함수.
// 위치 자체의 로직은 같기에, isPlace 변수를 추가로 할당하여 if문 처리.
void placeQueen(int y, int x, bool isPlace)
{
    int tmpY = y + 1;
    int tmpX = x - 1;
    while (tmpY < n && tmpX >= 0)
    {
        isPlace ? put[tmpY][tmpX]++ : put[tmpY][tmpX]--;
        tmpY++;
        tmpX--;
    }

    tmpY = y + 1;
    tmpX = x + 1;
    while (tmpY < n && tmpX < n)
    {
        isPlace ? put[tmpY][tmpX]++ : put[tmpY][tmpX]--;
        tmpY++;
        tmpX++;
    }
}

// k번째 줄에 놓일 퀸의 위치를 정하는 함수
void func(int k)
{
    if (k == n)
    {
        possible++;
        return;
    }

    for (int i{0}; i < n; i++)
    {
        if (!columnUsed[i] && put[k][i] == 0)
        {
            columnUsed[i] = 1;
            placeQueen(k, i, true);

            // k번째 줄에 퀸을 놓을 위치를 정하고 k+1번째 줄을 정하러 함수 호출.
            func(k + 1);

            // k번째 줄에 놓았던 퀸을 이용해서, 가능한 모든 경우를 탐색했다는 뜻.
            columnUsed[i] = 0;
            placeQueen(k, i, false);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    // i번째 줄에 놓일 퀸의 위치를 정하는 함수.
    // 한 줄에 퀸이 하나밖에 존재하지 않으니 가능한 함수의 형태.
    func(0);

    cout << possible;
}