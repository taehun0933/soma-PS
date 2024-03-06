#include<iostream>
#include<vector>

using namespace std;

string S; 
vector<int> alphaNum(26,0);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S;
    
    for(int i = 0; i<S.length(); i++){
        alphaNum[S[i]-'a']++;
    }

    for(int i = 0; i< 26; i++){
        cout <<alphaNum[i]<<' ';
    }
    return 0;
}