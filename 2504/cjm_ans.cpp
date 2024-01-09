#include<iostream>
#include<stack>

using namespace std;

string a;
stack<char> s; // 여는 괄호 저장
stack<int> x; // 계산된 값 순서대로 저장
stack<int> mess;
int fin;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    mess.push(0);

    for(int i =0;i<a.length();i++){ //왼쪽부터 각 괄호가 무엇인지 확인
        char cur = a[i]; //현재 괄호 받을 변수
        if(cur == '('||cur =='['){
            s.push(cur);
            if(i>0){
                if(a[i-1]=='('||a[i-1]=='['){
                    mess.push(x.size());
                }
            }
        }else if(cur == ')'){
            if(!s.empty()&&s.top() == '['){
                cout <<'0'<<'\n';
                return 0;
            }else if(s.empty()){
                cout <<'0'<<'\n';
                return 0;
            }
            if(s.top()==a[i-1]){
                x.push(2);
                s.pop();

            }else{
                s.pop();
                int q = x.size()-mess.top();
                int result=0;
                while(q--){
                    int c=x.top();
                    x.pop();
                    result += c;
                }
                x.push(result*2);
                mess.pop();
            }
        }else { // cur == ']'
            if(!s.empty()&& s.top() == '('){
                cout <<'0'<<'\n';
                return 0;
            }else if(s.empty()){
                cout <<'0'<<'\n';
                return 0;
            }
            if(s.top()==a[i-1]){
                x.push(3);
                s.pop();
            }else{
                s.pop();   
                int q = x.size()-mess.top();
                int result=0;
                while(q--){
                    int c=x.top();
                    x.pop();
                    result += c;
                }  
            }
        }
    }
    if(!s.empty()){
        cout <<'0'<<'\n';
        return 0;
    }
    while(!x.empty()){
        int q = x.top();
        x.pop();
        fin +=q;
    }
    cout <<fin;
    return 0;
}