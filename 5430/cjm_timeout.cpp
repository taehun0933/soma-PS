#include<iostream>
#include<vector>
#include<deque>
#include<sstream>

using namespace std;

int t;
char p;

void reverse(deque<int> &numDec){
    deque<int> reverseDec;

    while(!numDec.empty()){
        int last = numDec.back();

        numDec.pop_back();
        reverseDec.push_back(last);
    }
    numDec = reverseDec;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while(t--){
        deque<int> numDec;

        string p; //함수 뭉태기
        cin >> p;

        int n; //arr에 든 원소 개수
        cin >> n;

        string arr; //[1,2,3,4]
        cin >> arr;

        string temp="";

        for(char num : arr){
            if(isdigit(num)){
                temp+=num;
            }else{
                if(temp != ""){

                    numDec.push_back(stoi(temp));
                    temp ="";
                }
            }
        };

        cout << "\n";
        for(int i=0;i<p.length();i++){
            char func = p[i]; //실행할 함수

            //arr 이 빈배열이 아닌경우
            if(func == 'R'&& !numDec.empty()){    
                reverse(numDec);
                continue;
            }

            if(func == 'D'){
                if(numDec.empty()){ 
                numDec.push_back(0);

                break;
                }
                numDec.pop_front();
            }

        }
       
       if(!numDec.back()){
            cout << "error"<<"\n";
            continue;
        }else{
            cout << '[';
                for(int i : numDec) {
                    if(i != numDec.back() ){
                        cout << i << ',';
                    }
                }
            cout <<numDec.back()<< ']' << "\n";
        }
    }
    return 0;
}