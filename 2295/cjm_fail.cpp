#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n; //집합 U에 들어있는 자연수 개수. 5이상
int u[1001]; //집합 
int sum;
vector<int> combi;

//18 15 12 10 4 1

void func(int str, int idx){ //시작할 인덱스 받아오기, 합을 만들 놈이 얼마나 모였나
      if(!combi.empty()){
        for(int i=0;i<combi.size();i++){
            cout<< combi[i]<<' ';
        }
        cout << '\n';
    }
    if(sum == u[str] && combi.size() ==3){
        cout <<u[str];
        exit(0);
    }
    if(idx == 0 ){
        return;
    }


    if(combi.size()==3 && sum != u[str]){
        sum -= u[idx];
        combi.pop_back();
    }

    
    sum+=u[idx];
    combi.push_back(u[idx]); 
    func(str,idx-1);

    sum -= u[idx];
    combi.pop_back();
    func(str,idx-2);

     if(!combi.empty()){
        for(int i=0;i<combi.size();i++){
            cout<< combi[i]<<' ';
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //세수의 합이 집합에 들어있는 경우 중에 가장 큰 합을 출력해라

    //들어오는 원소의 값이 int 의 경계선 -> 값을 인덱스로 하는 것은 불가능?
    //5부터 출력값이 될 수 있음

    cin >> n;

    for(int i=1;i<n+1;i++){
        cin >> u[i];
    }

    cout << '\n';
    for(int i = n;i>4;i--){
        // cout <<i<<' '<<'\n';
        func(i,i-1);
        // cout <<'\n';
    }

}