#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int board[501][501];
int maxNum;

void getRotate()
{
    int tmp_board[501][501];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            tmp_board[j][n - 1 - i] = board[i][j];
    }

    swap(n, m);
    for (int i{0}; i < n; i++)
        for (int j{0}; j < m; j++)
            board[i][j] = tmp_board[i][j];
}

void flipX()
{
    for (int i{0}; i < n / 2; i++)
    {
        for (int j{0}; j < m; j++)
            swap(board[i][j], board[n - i - 1][j]);
    }
}

void flipY()
{
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m / 2; j++)
            swap(board[i][j], board[i][m - j - 1]);
    }
}

void judge(int i, int j)
{
    int sum{0};
    bool canPut{1};
    pair<int, int> nextPos1[4] = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
    for (pair<int, int> p : nextPos1)
    {
        int nx = i + p.first;
        int ny = j + p.second;

        // 배치 불가능
        if (nx >= n || ny >= m)
        {
            canPut = 0;
            break;
        }
        sum += board[nx][ny];
    }
    if (canPut && sum > maxNum)
        maxNum = sum;

    sum = 0;
    canPut = 1;
    pair<int, int> nextPos2[4] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    for (pair<int, int> p : nextPos2)
    {
        int nx = i + p.first;
        int ny = j + p.second;

        // 배치 불가능
        if (nx >= n || ny >= m)
        {
            canPut = 0;
            break;
        }
        sum += board[nx][ny];
    }
    if (canPut && sum > maxNum)
        maxNum = sum;

    sum = 0;
    canPut = 1;
    pair<int, int> nextPos3[4] = {{0, 0}, {1, 0}, {2, 0}, {2, 1}};
    for (pair<int, int> p : nextPos3)
    {
        int nx = i + p.first;
        int ny = j + p.second;

        // 배치 불가능
        if (nx >= n || ny >= m)
        {
            canPut = 0;
            break;
        }
        sum += board[nx][ny];
    }
    if (canPut && sum > maxNum)
        maxNum = sum;

    sum = 0;
    canPut = 1;
    pair<int, int> nextPos4[4] = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
    for (pair<int, int> p : nextPos4)
    {
        int nx = i + p.first;
        int ny = j + p.second;

        // 배치 불가능
        if (nx >= n || ny >= m)
        {
            canPut = 0;
            break;
        }
        sum += board[nx][ny];
    }
    if (canPut && sum > maxNum)
        maxNum = sum;

    sum = 0;
    canPut = 1;
    pair<int, int> nextPos5[4] = {{0, 0}, {0, 1}, {1, 1}, {0, 2}};
    for (pair<int, int> p : nextPos5)
    {
        int nx = i + p.first;
        int ny = j + p.second;

        // 배치 불가능
        if (nx >= n || ny >= m)
        {
            canPut = 0;
            break;
        }
        sum += board[nx][ny];
    }
    if (canPut && sum > maxNum)
        maxNum = sum;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i{0}; i < n; i++)
        for (int j{0}; j < m; j++)
            cin >> board[i][j];

    for (auto num : {0, 1, 1, 1})
    {
        if (num == 1)
            getRotate();

        for (int i{0}; i < n; i++)
        {
            for (int j{0}; j < m; j++)
                judge(i, j);
        }

        flipX();
        for (int i{0}; i < n; i++)
        {
            for (int j{0}; j < m; j++)
                judge(i, j);
        }
        flipX();

        flipY();
        for (int i{0}; i < n; i++)
        {
            for (int j{0}; j < m; j++)
                judge(i, j);
        }
        flipY();
    }

    cout << maxNum;
}