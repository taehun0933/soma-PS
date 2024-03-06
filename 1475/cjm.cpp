#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N;
int setNum =1;

vector<int> set(10,0);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    while(N>0){
        if(set[N%10] <setNum){
            set[N%10]++;
        }else if(N%10 == 6 && set[9] <setNum ){
            set[9]++;
        }else if(N%10 == 9 && set[6] <setNum ){
            set[6]++;
        }else{
            set[N%10]++;
            setNum ++;
        }
        N /= 10;
    }

    cout << setNum;
    return 0;
}