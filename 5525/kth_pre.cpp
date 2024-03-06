#include <iostream>
#include <string>
using namespace std;

int n, m;
string s;
int res;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> s;

    bool IStart{0};
    int length{0};

    for (int i{0}; i < s.length(); i++)
    {
        if (i == 0)
        {
            if (s[i] == 'I')
            {
                IStart = 1;
                length = 1;
            }
            continue;
        }

        // 이전과 다른지에 대한 비교
        if (s[i] == 'O')
        {
            if (s[i - 1] != s[i])
            {
                // IO
                length++;
            }
            else
            {
                // OO
                if (IStart)
                {
                    int len = length;
                    int numOfIOI{0};
                    while (len >= 3 + 2 * (n - 1))
                    {
                        numOfIOI++;
                        len -= 2;
                    }

                    res += numOfIOI;
                }

                IStart = 0;
                length = 0;
            }
        }
        else // s[i] == 'I'
        {
            if (s[i - 1] != s[i])
            {
                // OI
                if (IStart)
                    length++;
                else
                {
                    IStart = 1;
                    length = 1;
                }
            }
            else
            {
                // II
                // IStart = 0;

                // 더하기 후 IStart 다시 초기화

                if (IStart)
                {
                    int len = length;
                    int numOfIOI{0};
                    while (len >= 3 + 2 * (n - 1))
                    {
                        numOfIOI++;
                        len -= 2;
                    }

                    res += numOfIOI;
                }

                IStart = 1;
                length = 1;
            }
        }
    }

    if (IStart)
    {
        int len = length;
        int numOfIOI{0};
        while (len >= 3 + 2 * (n - 1))
        {
            numOfIOI++;
            len -= 2;
        }

        res += numOfIOI;
    }

    cout << res;
}