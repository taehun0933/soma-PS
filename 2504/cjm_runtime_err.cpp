#include<iostream>
#include<stack>

using namespace std;

string a;
stack<char> s; // 여는 괄호 저장
int calNum;
stack<int> x; // 계산된 값 순서대로 저장
stack<int> mess;
int fin;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    mess.push(0);

    for(int i =0;i<a.length();i++){ //왼쪽부터 각 괄호가 무엇인지 확인
        char cur = a[i]; //현재 괄호 받을 변수
        // cout << cur<<'\n';
        if(cur == '('||cur =='['){
            s.push(cur);
            //이 부분 왜
            if(i>0){
                if(a[i-1]=='('||a[i-1]=='['){
                    mess.push(x.size());
                    // cout << i+1 << " mess ="<<mess.top()<<'\n';
                }
            }

        }else if(cur == ')'){
            if(!s.empty()&&s.top() == '['){
                // cout << "왜 멈춰"<<i<<s.top()<<'\n';
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
                // cout << i+1 <<" q ="<<x.size()<<'-'<<mess.top()<<' '<< q<<'\n';


                while(q--){
                    int c=x.top();
                    x.pop();
                    result += c;
                    // cout << i+1 << "번째 x 빼낸거"<<c <<'\n';
                }
                // cout << i+1 <<"괄호 내부에서 다 더한 결과값 = " << result<<"  mess 값 ="<<mess.top()<<'\n';

                x.push(result*2);
                mess.pop();

            }
        }else { // cur == ']'
            if(!s.empty()&& s.top() == '('){
                // cout << "왜 멈춰"<<i<<s.top()<<'\n';

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
                // cout << i+1 <<" q ="<<x.size()<<'-'<<mess.top()<<' '<< q<<'\n';

                while(q--){
                    int c=x.top();
                    x.pop();
                    result += c;
                }  
                mess.pop();
                x.push(result*3);

            }
        }
    }

    //출력값 2 6 6 => 왜 size가 2인데 반복은 한번만해>???
    // cout <<x.size()<<'\n';
    // for(int i=0;i<x.size();++i){
    //     int q = x.top();
    //     x.pop();
    //     fin +=q;
    //     cout << fin<<'\n';
    // }
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