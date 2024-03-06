#include<iostream>
#include<list>

using namespace std;

string txt;
list<char> txts;
int N,M;
char command, plusTxt;

int main(){
    cin >> txt;
    cin >> M;

    for(char i : txt) {
        txts.push_back(i);
    }
    auto t = txts.end();
    
    for(int i = 0; i<M; i++){
        cin >> command;

        if(command == 'L' && t != txts.begin()) t--;
        if(command == 'D' && t != txts.end()) t++;
        if(command == 'B' && t != txts.begin()) {
            t--;
            t = txts.erase(t);
        }
        if(command == 'P'){
            cin >> plusTxt;
            txts.insert(t,plusTxt);
        }
    }

    for(auto i : txts) cout << i;

    return 0;
}