#include<iostream>
#include<stack>

using namespace std;

stack<int> topList;
stack<int> topNum;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >>n;

    int f;
    cin >>f;

    topList.push(f);
    topNum.push(1);
    cout << '0' <<' ';

    for(int i =1;i<n;i++){
        int newTop;

        cin >> newTop;

        //오른쪽(새로 들어온 값)이 왼쪽(top)보다 큰 경우
        while(!topList.empty()&& newTop >= topList.top()){
            //기존 top 없앰
            topList.pop();
            topNum.pop();
        }
        
        if(topNum.empty()){
            cout << '0'<<' ';
        }else{
            cout << topNum.top()<<' ';
        }

        topNum.push(i+1);
        topList.push(newTop);
    }
    return 0;
}