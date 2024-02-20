#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<int> num;
vector<char> plma;

int ans;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //최솟값 만들어서 최솟값 출력
    //다 같은 부호면 바로 결과 출력
    //-뒤에 나오는 +들을 다 더해서 빼는게 최고
      //-뒤에 -나오면 묶지말고
    // ㅁ - ㅁㅁ-ㅇ+ㅇㅇ+ㅇ+ㅇ-ㅇㅇ-ㅇ-ㅇ

    string s;
    cin>>s;
    int lastIDX=0;x
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'||s[i]=='+'){
            int curNum = stoi(s.substr(i,i+1 - lastIDX)); 
            num.push_back(curNum);//숫자 넣어주고
            
            lastIDX=i;
            plma.push_back(s[i]);
        }
        if(i==s.length()-1){
            int curNum = stoi(s.substr(i,i+1 - lastIDX)); 
            num.push_back(curNum);//숫자 넣어주고
        }
    }

    int cur=0;
    // int pre=0;
    int plusSum=0;
    bool isminus =false;
    for(int i=1;i<plma.size();i++){

        if(plma[i] == '+'){
            // int newN = num[i] +num[i+1];
            // num[i+1] += num[i];

            // pre = cur+pre;
            if(isminus==true){
                plusSum += num[i]; 
            }else{
                ans +=num[i];
            }
        }else if(plma[i] == '-'){
            if(isminus==false){
                isminus= true;
                pre=num[i];

            } else{
                //지금까지 더해준 것들을 빼주기

            }



            // while(plma[i+1] == '+'){
            //     num[i+1] += num[i+2];
            //     i++;
            // }

        }
    }


    
}