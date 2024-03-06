#include<iostream>
#include<stack>
using namespace std;

string orders;
int N;
stack<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> orders;

        if(orders == "push") {
            int x;
            cin >> x;
            s.push(x);
        }else if(orders == "pop"){
            if(s.empty()) {
                cout << "-1"<<"\n";
            }else{
                cout << s.top()<<"\n";
                s.pop();
            }
            
        }else if(orders == "size"){
            cout << s.size()<<"\n";
        }else if(orders == "empty"){
            bool emp = s.empty();
            cout << emp << "\n";
            // if(s.empty()){
            //     cout << '1';
            // }else{
            //     cout << '0';
            // }

        }else if(orders == "top"){
            if(s.empty()) {
                cout << "-1"<<"\n";
            }else{
                cout << s.top()<<"\n";
            }
        }
        
    }


}   