#include<iostream>
#include<deque>
using namespace std;

int n,m;
deque<int> que;
int result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i< n+1; i++) que.push_back(i);

    while(m--){
        int pick;
        cin >>pick;
        
        int count =0;

        while(que.front() != pick){
            int pop = que.front();
            que.pop_front();
            que.push_back(pop);
            count++;
        }
        if(que.size() - count < count) count = que.size() - count;

        que.pop_front();
        result += count;
    }
    cout <<result;
}