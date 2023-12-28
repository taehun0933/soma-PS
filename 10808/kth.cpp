#include <iostream>
using namespace std;

string s;
int numOfAlpha[26];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;

    for (char c : s)
        numOfAlpha[c - 'a']++;

    for (int i : numOfAlpha)
        cout << i << " ";
}