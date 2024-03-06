#include <iostream>
#include <string>
using namespace std;

// - 발견 => +가 나올때까지 묶기
string s;
int res;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    string s_num = "";
    char mode = '+';
    for (auto c : s)
    {
        if (c != '-' && c != '+')
            s_num += c;

        else
        {
            if (mode == '+')
                res += stoi(s_num);
            else
                res -= stoi(s_num);

            s_num = "";

            if (c == '-')
                mode = '-';
        }
    }

    if (mode == '+')
        res += stoi(s_num);
    else
        res -= stoi(s_num);

    cout << res;
}