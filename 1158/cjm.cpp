#include<iostream>
#include<vector>
#include<list>
using namespace std;

list<int> circle;
vector<int> deleteNum;
int N,K;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>> N >> K;

    for(int i = 1; i< N+1;i++){
        circle.push_back(i);
    }
    auto t = circle.begin();

    while(circle.size() != 0){
        for(int i =0; i<K-1;i++){
            t++;
            if(t == circle.end()) t = circle.begin();
        }
        deleteNum.push_back(*t);
        t = circle.erase(t);
        if(t == circle.end()) t = circle.begin();

    }

    for(int i=0;i<deleteNum.size();i++){
        cout<< deleteNum[i];
    }

    return 0;
}