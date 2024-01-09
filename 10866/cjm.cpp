#include<iostream>
#include<deque>

using namespace std;

int n;
deque<int> num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>n;
    while(n--){
        string command;
        cin >> command;

        if(command == "push_front"){
            int x;
            cin >> x;

            num.push_front(x);
        }else if(command == "push_back"){
            int x;
            cin >> x;

            num.push_back(x);
        }else if(command == "pop_front"){
            if(num.empty()) {
                cout << "-1" <<"\n";
                continue;
            }

            cout << num.front()<<"\n";
            num.pop_front();
        }else if(command == "pop_back"){
            if(num.empty()) {
                cout << "-1" <<"\n";
                continue;
            }

            cout << num.back()<<"\n";
            num.pop_back();
        }else if(command == "size"){
        
            cout << num.size()<<"\n";
        }else if(command == "empty"){
        
            cout << num.empty() <<"\n";
        }else if(command == "front"){
            if(num.empty()) {
                cout << "-1" <<"\n";
                continue;
            }
            cout << num.front() << "\n";
        }else{
            //back
            if(num.empty()) {
                cout << "-1" <<"\n";
                continue;
            }
            cout << num.back() << "\n";

        }

    }

}