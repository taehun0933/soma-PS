#include <iostream>
#include <string>
using namespace std;

// for문을 돌며 I를 보는 순간, 뒤로 가며 IOIOIOI ... 가 얼마나 있는지를 찾으면 됨.
//  -> 뒤의 문자 1개가 아닌, 2개씩 보면 복잡한 절차가 필요하지 않다.
// IOI 형태가 끝난다면, 진행한 만큼 실제 for문을 진행시킴.

int n, m;
string s;
int res;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> s;
    for (int i{0}; i < s.length(); i++)
    {
        if (s[i] == 'I')
        {
            // IOIOI -> n이 2면 1
            // I 이후 OI가 n번 나오면 최소 IOI식 완성.
            // 이후 OI가 한번 나올 때마다 numOfIOI 1 증가.
            int k{0};
            int numOfIOI{0};
            while (i + 2 < s.length() && i + 2 < s.length() && s[i + 1] == 'O' && s[i + 2] == 'I')
            {
                i += 2;
                k++;

                if (k == n)
                {
                    numOfIOI++;
                    k--;
                }
            }
            res += numOfIOI;
        }
    }
    cout << res;
}