#include<iostream>
using namespace std;

long long fibo[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    fibo[1] =1;
    fibo[2] = 1;

    for(int i=3; i<n+1; i++){
        fibo[i] = fibo[i-1]+fibo[i-2];
    }
    cout <<fibo[n];

}