#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int n, m;
int board[10][10];

void getRotate()
{
    int tmpBoard[10][10];

    // for문에서 n -> m 순서가 아닌, m -> n 순서로 진행
    for (int i{0}; i < m; i++)
        for (int j{0}; j < n; j++)
            tmpBoard[i][j] = board[n - j - 1][i];

    for (int i{0}; i < m; i++)
        for (int j{0}; j < n; j++)
            board[i][j] = tmpBoard[i][j];

    // 행 - 열 크기가 바뀌었으므로, swap 처리
    swap(n, m);
}

void printBoard()
{
    for (int i{0}; i < n; i++)
    {
        for (int j{0}; j < m; j++)
        {
            cout.width(2);
            cout << std::left << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    n = 5;
    m = 10;

    for (int i{0}; i < n; i++)
        for (int j{0}; j < m; j++)
            board[i][j] = 10 * i + j;

    cout << "원본\n";
    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
    printBoard();
    cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";

    for (int i{0}; i < 3; i++)
    {
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
        cout << "90도 회전 : 총 " << i + 1 << "회\n";
        getRotate();
        printBoard();
        cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n";
    }
}