#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, result;
// 한 행에는 하나의 퀸만 존재할 수 있음
int board[14]; // 각 행의 몇 열에 퀸이 들어가있는지를 저장할 배열
bool isFalse;

void queen(int num)
{ // i번째 줄에 적절한 퀸을 놓는 함수
    if (num == n)
    {
        result++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        board[num] = i; // 각 행의 모든 칸에 둬보기

        for (int j = 0; j < num; j++)
        {
            if (board[num] == board[i] || num - j == abs(board[num] - board[j]))
            { // 다음줄에 놓을 수 있는지만 생각하면 됨
                isFalse = 1;
                break;
            }
            if (isFalse == 1)
                break;
        }
        if (isFalse == 0)
            queen(num + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(board, board + 14, -1); // -1로 초기화

    cin >> n;
    queen(0); // 현재 배치된 queen의 개수 (= 행 넘버) 를 넘겨줌
    cout << result;
    return 0;
}