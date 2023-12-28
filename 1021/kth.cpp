#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int n, m;
// 1~N까지 담을 deque
deque<int> DQ;

// 순서대로 뽑기 위한 정보를 담은 queue
queue<int> Q;
int numOfCalc;

int getLeftRotateNum(int numToFind, deque<int> DQ)
{
    int leftRotateNum{0};
    while (numToFind != DQ.front())
    {
        int num = DQ.front();
        DQ.pop_front();
        DQ.push_back(num);
        leftRotateNum++;
    }
    return leftRotateNum;
}

int getRightRotateNum(int numToFind, deque<int> DQ)
{
    int rightRotateNum{0};
    while (numToFind != DQ.front())
    {
        int num = DQ.back();
        DQ.pop_back();
        DQ.push_front(num);
        rightRotateNum++;
    }
    return rightRotateNum;
}

void leftRotate()
{
    int num = DQ.front();
    DQ.pop_front();
    DQ.push_back(num);
}

void rightRotate()
{
    int num = DQ.back();
    DQ.pop_back();
    DQ.push_front(num);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i{1}; i <= n; i++)
        DQ.push_back(i);

    while (m--)
    {
        int i;
        cin >> i;
        Q.push(i);
    }

    while (!Q.empty())
    {
        // 원소 뽑기
        int numToFind = Q.front();
        Q.pop();

        int leftRotateNum{0};
        int rightRotateNum{0};
        leftRotateNum = getLeftRotateNum(numToFind, DQ);
        rightRotateNum = getRightRotateNum(numToFind, DQ);

        if (leftRotateNum < rightRotateNum)
        {
            numOfCalc += leftRotateNum;
            while (leftRotateNum--)
                leftRotate();
            DQ.pop_front();
        }
        else
        {
            numOfCalc += rightRotateNum;
            while (rightRotateNum--)
                rightRotate();
            DQ.pop_front();
        }
    };

    cout << numOfCalc;
}