
#include<iostream>
#include<stack>
using namespace std;

int n; //탑의 개수
int receives[500000]; // 출력값 담을 배열

stack<int> counts;
stack<int> tops;

bool hi;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    receives[0] =0;
    counts.push(0);

    for(int i=0; i<n;i++){
        int a;
        cin >> a;
        if(!i) tops.push(a);
        if(i != 0 ){
            if(a >= tops.top()){
                tops.pop();
                counts.pop();
                while(hi){
                    tops.push(a);
                    counts.push(i+1);
                    if(a >= tops.top()){
                       
                        tops.pop();
                        counts.pop();
                        
                        receives[i+1] = 0;
                        hi = 0;
                    }else{
                        receives[i+1] = counts.top();
                    }
                }
               
            }else{
                tops.push(a);
                counts.push(i+1);

                receives[i+1] = counts.top();
                counts.push(i+1);
            }
        }
    }
    
    for(int i:receives) cout << i;
}