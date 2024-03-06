#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
int u[1005];
vector<int> two;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i =0;i<n;i++){
        cin >>u[i];
    }
    sort(u,u+n);

    for(int i =0;i<n;i++){
        for(int j=i;j<n;j++){
            two.push_back(u[i]+u[j]);
        }
    }

    sort(two.begin(),two.end());
    for(int i =n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(binary_search(two.begin(),two.end(),u[i]-u[j])){
                cout <<u[i];
                return 0;
            }
            
        }
    }


}