#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // bool isEnd = false;

    while(1){ // 한 문장별로 실행할 함수
        string sentence;
        getline(cin,sentence); //공백 포함 문자열 받기

        if(sentence == ".") break;
        

        stack<char> pair;
        
        for(int i =0; i<sentence.length();i++){
            char word = sentence[i];

            if(word == '(' || word == '['){
                pair.push(word);

            }else if(word == ')'){
                if(pair.empty()) {
                    pair.push(0);
                    break;
                }
                char left = pair.top();
                if(left =='('){ 
                    pair.pop();
                }else{
                    break;
                }

            }else if(word == ']'){
                if(pair.empty()) {
                    pair.push(0);
                    break;
                }
                char left = pair.top();
                if(left =='['){ 
                    pair.pop();
                }else{
                    break;
                }
            }
        }

        if(pair.empty()){
            cout << "yes"<<"\n";
        }else{
            cout << "no"<<"\n";
        }

    }
    return 0;
}