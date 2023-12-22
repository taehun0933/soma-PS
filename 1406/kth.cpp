#include <iostream>
#include <list>
using namespace std;

string s;
int m;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    cin >> m;

    list<char> txt;
    for (char c : s)
        txt.push_back(c);
    list<char>::iterator i = txt.end();

    while (m--)
    {
        char c;
        cin >> c;
        switch (c)
        {
        case 'L':
            if (i != txt.begin())
                i--;
            break;
        case 'D':
            if (i != txt.end())
                i++;
            break;
        case 'B':
            if (i != txt.begin())
                i = txt.erase(--i);
            break;
        case 'P':
            char c;
            cin >> c;
            txt.insert(i, c);
            break;
        }
    }

    for (list<char>::iterator it = txt.begin(); it != txt.end(); it++)
        cout << *it;
}