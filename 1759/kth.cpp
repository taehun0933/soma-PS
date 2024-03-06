#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char alphabets[16];

// k번째로 올 문자를 완성하는 함수
void func(int k, string code, int idx)
{
    if (k == l)
    {
        int zaum{0}, moeum{0};
        for (auto c : code)
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                moeum++;
            else
                zaum++;

        if (zaum >= 2 && moeum >= 1)
            cout << code << "\n";
    }
    for (int i{idx}; i < c; i++)
        func(k + 1, code + alphabets[i], i + 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c;
    for (int i{0}; i < c; i++)
        cin >> alphabets[i];

    sort(alphabets, alphabets + c);

    func(0, "", 0);
}