#include <iostream>
using namespace std;

int chess[15][15];
int n;
int possible;

// {y,x} 자리에 퀸을 놓음으로서, 체스판 상의 놓을 수 없는 위치를 결정하는 함수
void place(int y, int x)
{
    // 가로
    for (int i{0}; i < n; i++)
    {
        if (i != x)
            chess[y][i]++;
    }

    // 세로
    for (int i{0}; i < n; i++)
    {
        if (i != y)
            chess[i][x]++;
    }

    // X자로 확장
    // 남서방향
    int tmpY = y + 1;
    int tmpX = x - 1;
    while (tmpY < n && tmpX >= 0)
    {
        chess[tmpY][tmpX]++;
        tmpY++;
        tmpX--;
    }

    // 북동방향
    tmpY = y - 1;
    tmpX = x + 1;
    while (tmpY >= 0 && tmpX < n)
    {
        chess[tmpY][tmpX]++;
        tmpY--;
        tmpX++;
    }

    // 북서방향
    tmpY = y - 1;
    tmpX = x - 1;
    while (tmpY >= 0 && tmpX >= 0)
    {
        chess[tmpY][tmpX]++;
        tmpY--;
        tmpX--;
    }

    // 남동방향
    tmpY = y + 1;
    tmpX = x + 1;
    while (tmpY < n && tmpX < n)
    {
        chess[tmpY][tmpX]++;
        tmpY++;
        tmpX++;
    }
}

// {y,x} 자리의 퀸을 제거함으로서, 기존 {y,x}의 퀸으로 인해 못 놓게 되었던 자리를 복구하는 함수
void outPlace(int y, int x)
{
    // 가로
    for (int i{0}; i < n; i++)
    {
        if (i != x)
            chess[y][i]--;
    }

    // 세로
    for (int i{0}; i < n; i++)
    {
        if (i != y)
            chess[i][x]--;
    }

    // X자로 확장

    // 남서방향
    int tmpY = y + 1;
    int tmpX = x - 1;
    while (tmpY < n && tmpX >= 0)
    {
        chess[tmpY][tmpX]--;
        tmpY++;
        tmpX--;
    }

    // 북동방향
    tmpY = y - 1;
    tmpX = x + 1;
    while (tmpY >= 0 && tmpX < n)
    {
        chess[tmpY][tmpX]--;
        tmpY--;
        tmpX++;
    }

    // 북서방향
    tmpY = y - 1;
    tmpX = x - 1;
    while (tmpY >= 0 && tmpX >= 0)
    {
        chess[tmpY][tmpX]--;
        tmpY--;
        tmpX--;
    }

    // 남동방향
    tmpY = y + 1;
    tmpX = x + 1;
    while (tmpY < n && tmpX < n)
    {
        chess[tmpY][tmpX]--;
        tmpY++;
        tmpX++;
    }
}

// k개만큼 퀸을 둔 후에 다음 퀸을 놓을 위치를 결정하는 함수
void func(int k, int y, int x)
{
    if (k == n)
    {
        possible++;
        return;
    }

    // 중복 문제 제거를 위해, {y,x}의 좌표부터 시작.
    // 최대 시간 절약을 위해 for문을 두 번 사용하였음.
    for (int j{x}; j < n; j++)
    {
        // 지금까지 해당 칸이 영향을 받지 않았을 경우, 즉 chess 칸의 값이 0일 경우
        if (chess[y][j] == 0)
        {
            chess[y][j]++;
            place(y, j);

            func(k + 1, y, j);

            chess[y][j]--;
            outPlace(y, j);
        }
    }

    for (int i{y + 1}; i < n; i++)
    {
        for (int j{0}; j < n; j++)
        {
            // 지금까지 해당 칸이 영향을 받지 않았을 경우, 즉 chess 칸의 값이 0일 경우
            if (chess[i][j] == 0)
            {
                chess[i][j]++;
                place(i, j);

                func(k + 1, i, j);

                chess[i][j]--;
                outPlace(i, j);
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    func(0, 0, 0);
    cout << possible;
}