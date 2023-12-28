#include<iostream>
#include<stack>

using namespace std;
string a;
stack<char> s;
int stick;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0); 
    
    cin >> a;

    for(int i =0;i<a.length();i++){
        char c = a[i];

        if(c == '('){
            s.push(c);
        }else { //c == ')'

            if(a[i-1] == ')') { // 이건 막대기
                stick += 1;
                s.pop();
            }else{ // 레이저
                s.pop();
                int front = s.size();   
                stick += front; // 해당 레이저가 자른 막대기 개수
            }
        }
    }
    cout << stick;
}