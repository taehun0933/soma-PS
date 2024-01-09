#include<iostream>
#include<stack>

using namespace std;

int k;
long long int sum;
stack<int> arr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k;

    for(int i=0;i<k;i++){
        int a;
        cin >> a;

        if(a == 0){
            arr.pop();
        }else{
            arr.push(a);
        }
    }

    while(arr.size() >0){
        sum += arr.top();
        arr.pop();
    }
    cout <<sum;
}