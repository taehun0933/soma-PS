#include <iostream>
using namespace std;

int n, k; // n=원판 개수 // k= 옮긴횟수
// 2^n-1번 옮겨야 함

void hanoi(int n, int start, int sub, int des)
{
    if (n == 1)
    {
        k++;
        cout << start << ' ' << des << '\n';
        return;
    }

    hanoi(n - 1, start, des, sub); // n-1개를 sub로 옮기고
    k++;
    cout << start << ' ' << des << '\n';
    hanoi(n - 1, sub, start, des);
    // sub = start 가 되고 des는 그대로 -> Main 에서 함수 호출해주는 역할
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << pow(2, 20);
}