#include <iostream>
#include <string>
using namespace std;

int m;
string n;
bool broken[10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    while (m--)
    {
        int b;
        cin >> b;
        broken[b] = 1;
    }

    int minPress = abs(stoi(n) - 100);

    // 가능한 모든 수 나열.
    for (int i{0}; i <= 1000000; i++)
    {
        string sNum = to_string(i);

        bool canGo{1};

        for (char c : sNum)
            if (broken[c - '0'])
            {
                canGo = 0;
                break;
            }

        if (!canGo)
            continue;

        // i를 이용, 판단
        int press = sNum.length();
        press += abs(stoi(n) - i);

        if (minPress > press)
            minPress = press;
    }
    cout << minPress;
}