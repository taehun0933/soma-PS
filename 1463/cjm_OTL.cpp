#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[1000001]; // arr[i] 는 i에 도달하는데 걸린 최소 연산 횟수이다 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>> n;
    arr[1] = 0;

    // n/3 n/2 n-1 중에 가능한 것들 중에 가장 작은 값을 찾고 그거 +1 
    for(int i = 2; i<n+1;i++) {
        int minNum = arr[i-1];
        if(i%3 == 0){
            minNum = min(arr[i/3],minNum);
        }
        if(i%2 == 0){
            minNum = min(arr[i/2],minNum);
        }
        
        arr[i] = minNum +1;  
    }
    cout << arr[n];
}