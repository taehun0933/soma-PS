#include<iostream>
using namespace std;

int n,x;
int a[100000];
bool aNum[2000001];
int pairs;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>n;
    
    for(int i =0; i<n;i++){
        cin>>a[i];
        aNum[a[i]] = true;
    }

    cin >> x;

    for(int i =0; i<n;i++){
        if(x>=a[i]&&aNum[x-a[i]]) {
            pairs++;
        }
    }

    cout << pairs/2;
    return 0;
}