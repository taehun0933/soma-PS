#include<iostream>
#include<queue>

using namespace std;

queue<int> commnads;
int n;

int main(){ 
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while(n--){

        string order;
        cin >> order;

        if(order == "push"){
            int x;
            cin >> x;

            commnads.push(x);

        }else if(order == "front"){
            if(commnads.empty()) {
                cout << "-1"<<"\n";
                continue;
            }
            cout << commnads.front()<<"\n";

        }else if(order == "back"){
            if(commnads.empty()) {
                cout << "-1"<<"\n";
                continue;
            }
            cout << commnads.back()<<"\n";

        }else if(order == "pop"){
            if(commnads.empty()) {
                cout << "-1"<<"\n";
                continue;
            }
            cout << commnads.front()<<"\n";
            commnads.pop();

        }else if(order == "size"){
            cout << commnads.size()<<"\n";

        }else{
            if(commnads.empty()){
                cout << '1'<<"\n";
                continue;
            };
            cout << '0'<<"\n";

        };
    };
};