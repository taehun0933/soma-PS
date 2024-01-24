#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n,num;
//가능한 모든 경우를 해보아야한다 
//그냥 1을 빼는 경우, 3, 2로 나누고 1을 뺴는 경우
// 결과값이 1보다 작으면 return
// 결과깂이 1이면  -> 가장 빨리 도달한 것  -> 그대로 출력하고 끝내기 bfs

queue<int> Q; // 줄어드는(각 경우에 도달한 값을 저장할 큐)
int vis[1000001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    fill(vis,vis+1000001,-1);

    vis[n] =0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == 1){
            cout <<vis[cur];
            break;
        }
        if(cur -1 <1) continue;
        if(cur % 3 == 0){
            if(vis[cur /3] == -1) {
                vis[cur /3] = vis[cur] +1;
            }
            Q.push(cur/3);
        }
        if(cur % 2 == 0){
            if(vis[cur /2] == -1) {
                vis[cur /2] = vis[cur] +1;
            }
            Q.push(cur /2);
        }
        if(vis[cur-1] == -1) {
            vis[cur-1] = vis[cur] +1;
            Q.push(cur -1);
        }

    }
}