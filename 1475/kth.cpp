#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int numNeeded[10];
string n;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (char c : n)
        numNeeded[c - '0']++;

    if (numNeeded[6] || numNeeded[9])
    {
        numNeeded[6] = round(static_cast<double>(numNeeded[6] + numNeeded[9]) / 2);
        numNeeded[9] = 0;
    }

    cout << *max_element(numNeeded, numNeeded + 10);
}