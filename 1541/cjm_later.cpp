#include<iostream>
#include<vector>
#include <string>
using namespace std;

int ans;
bool isMIN = false;
string num;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //-가 나오면 그 뒤의 값은 다 빼주기 
    string s;
    cin >>s;

    int n = s.length();
    for(int i=0;i<n+1;i++){
        if(i==n){
            if(isMIN){
                ans-= stoi(num);
            }else{
                ans+= stoi(num);
            }
            break;
        }
        if(s[i]=='+'){
            if(isMIN){
                ans-= stoi(num);
            }else{
                ans+= stoi(num);
            }
            num = "";
        }else if(s[i]=='-'){
            if(!isMIN){
                isMIN = true;
                ans+= stoi(num);
                num = "";
            }else{
                ans-= stoi(num);
                num = "";
            }
            
        }else{
            num += s[i];
        }
       
    }

    cout <<ans;
    
}

