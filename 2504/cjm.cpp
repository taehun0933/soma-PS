#include<iostream>
#include<stack>

using namespace std;

string a;
stack<char> s; // 여는 괄호 저장
int calNum;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>a;    
    stack<int> x; // 계산된 값 순서대로 저장

    for(int i=0;i<a.length();i++){
        char c = a[i];
        if(!x.empty()) cout << c<<' '<<x.top()<<"\n";

        if(c=='('||c=='['){ 
            s.push(c);
            if(i>0){
                if(a[i-1] =='('||a[i-1] =='['){
                    calNum ++;
                }
                // if(!x.empty() && s.empty()){
                //     calNum ++;
                // }
            }

        }else if(c==')'){   
cout <<"인지함";
            if (s.top() == '['){ //틀린 괄호열
                cout << '0';
                return 0;
            }else {// 짝 맞는 괄호 -> 1. 새끼값이 존재하는지 확인 2.값으로 변경
                s.pop();

                //x에 값이 들어있으면 계산 
                if(!x.empty() && calNum < x.size()){

                    int p = x.top();
                    x.pop();
                    
                    int q = x.top();
                    x.pop();
                    cout << "gkgk";
                    x.push(p+q);
                    calNum--;
                }else if(!x.empty() && calNum == x.size()){
                    
                    int b = x.top();

                    cout << 2*b;
                    x.pop();
                    calNum --;
                    x.push(2*b);
                    // if(!x.empty() && s.empty()){
                    //     calNum ++;
                    // }
                }else{
                    x.push(2); // () => 2
                }

            }

        }else{ // c == ]
            
            if (s.top() == '('){ //틀린 괄호열
                cout << '0';
                return 0;
            }else {// 짝 맞는 괄호 -> 값으로 변경
                s.pop();

                if(!x.empty() && calNum < x.size()){
                    
                    int p = x.top();
                    x.pop();
                    // x.push(2+p);
                    int q = x.top();
                    x.pop();

                    x.push(p+q);
                    calNum--;
                
                }else if(!x.empty() && calNum == x.size()){
                
                    int b = x.top();
                    cout << 3*b;
                    x.pop();
                    cout <<c;
                    calNum --;
                    x.push(3*b);
                    // if(!x.empty() && s.empty()){
                    //     calNum ++;
                    // }
                }else{
                    x.push(3); // [] => 3
                }
            }
        }
    }
    if(!x.empty()){
        cout << x.top();
    }else{
        cout << "x 빔";
    }
    return 0;
}