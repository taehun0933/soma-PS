#include<iostream>
#include<vector>
#include<deque>
#include<sstream>
#include<string>

using namespace std;

int t; // 테스트케이스
deque<int> numDec; //[1,2,3,4] 등 문자열 입력받은 값 파싱해서 저장할 덱

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;

    while(t--){ //각 테스트 케이스 별로 실행할 코드
        numDec.clear(); // [1,2,3,4] 들어갈 덱 초기화 
        int rNum =2; // 순서 뒤바꾸는게 몇 번인지 저장할 덱(홀수번이면 덱의 back 부터 출력, D는 덱의 back 부터 pop )

        string p=""; //수행할 함수 뭉치 R과 D
        cin >> p;

        int n=0; //arr에 든 원소 개수
        cin >> n;

        string arr=""; //[1,2,3,4]를 괄호까지 스트링으로 받음
        cin >> arr;

        string temp=""; //값이 두자리 수 일 경우를 위해 값을 저장했다가 숫자가 아닌 값이 나오면 temp에 저장된 문자를 numDec 에 저장함
		bool error_check = false; //에러인 경우 바로 에러 출력하도록 함

        for(char num : arr){ //string 형식으로 받은 배열을 실제 배열로 저장하는 코드
            if(isdigit(num)){
                temp+=num;
            }else{
                if(temp.size() != 0){
                    numDec.push_back(stoi(temp));
                    temp ="";
                }
            }
        };

        for(int i=0;i<p.length();i++){  //수행할 함수 뭉치의 길이만큼 반복 
            char func = p[i]; //뭉태기를 각각의 함수로 쪼개서 어떤 함수 실행하는지 확인

            //rNum만 +1 해주고 실제로 순서를 바꾸는 행위는 하지 않음
            if(func == 'R'){    
                rNum++;
                continue;
            }

            if(func == 'D'){
                if(numDec.empty()){ 
                    cout << "error"<<"\n";
                    error_check = true;
                    break;
                }else if(rNum %2 != 0){ //R이 홀수번 실행되는 경우 = 순서가 뒤바뀌어야 된 경우
                    numDec.pop_back();
                }else{ //순서가 뒤바뀔 필요 없음
                    numDec.pop_front();
                }
            }
        }
        if (error_check)
			continue;

       if(numDec.empty()){
        cout <<"[]"<<"\n";
       }else{
            cout << '[';
            if(rNum%2 == 0){ // 짝수번 r 실행
            // for(int i : numDec) {
            //         if( i != numDec.back() ){
            //             cout << i << ',';
            //         }
            //     } 
                while(numDec.size() > 1) {
                    cout <<numDec.front()<< ',';
                    numDec.pop_front();                   
                } 
                cout <<numDec.back()<< ']'<<"\n";

            }else if(rNum%2 != 0){ //홀수번 r 실행
                while(numDec.size() > 1) {
                    cout <<numDec.back()<< ',';
                    numDec.pop_back();                   
                } 
                cout <<numDec.front()<< ']'<<"\n";
            } 
       }
       
    }
    return 0;
}