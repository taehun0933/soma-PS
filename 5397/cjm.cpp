#include<iostream>
#include<list>

using namespace std;

int n; //테스트케이스 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    for(int i =0;i<n;i++){
        list<char> passwordIn;
        
        string passLong;
        cin >> passLong;
        list<char>::iterator t;
        
        for(int i =0; i< passLong.length();i++){
            char pass = passLong[i];
            bool isEmpty = passwordIn.empty();

            if(pass=='<'){
                if(isEmpty){
                    t= passwordIn.begin();
                    continue;
                }
                if(t != passwordIn.begin()) t--;

            }else if(pass=='>' ){
                if(isEmpty){
                    t= passwordIn.begin();
                    continue;
                }
                if(t != passwordIn.end()) t++;
            }else if(pass=='-'){
                if(isEmpty){
                    t= passwordIn.begin();
                    continue;
                }
                // if(t == passwordIn.end())
                if(t != passwordIn.begin()){
                    t--;
                    t = passwordIn.erase(t);
                }
                
            }else{
                if(isEmpty){
                    passwordIn.push_back(pass);
                    t= passwordIn.end();
                    continue;
                }
                passwordIn.insert(t,pass);

            }
        };

        for(auto iter = passwordIn.begin(); iter != passwordIn.end();iter++) cout << *iter;
        cout << '\n';
    };
    return 0;
};