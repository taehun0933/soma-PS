#include<iostream>
using namespace std;

int n;
int arr[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n ;
    
    fill(arr,arr+1000001,-1);
    arr[1] = 0;

    for(int i= 1;i<n;i++){
            for(int j : {i+1,i*2,i*3}){
             if(j== n){
                ;
             }
            if(arr[j] >arr[i]+1){
                arr[j] = arr[i]+1;
            }
        }
    }
}