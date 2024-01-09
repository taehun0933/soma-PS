#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>

using namespace std;
#define X first
#define Y second

int board[1002][1002]; // 0 1 -1 입력 받을 것
int dis[1002][1002];//거리 측정용
queue<pair<int,int>> Q; // 현재, 다음 칸 담을 큐

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >>m>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 0) dis[i][j] = -1;
            if(board[i][j] == 1) Q.push({i,j});
        }
    }

    // 1인 익은 토마토를 찾은 경우 거기서 부터 bfs
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); 
        Q.pop();
        for(int i=0;i<4;i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx< 0||nx>= n|| ny <0|| ny >= m) continue;
            if(dis[nx][ny] >= 0) continue; // 다음 목적지가 이미 방문한 곳이거나, 토마토가 안든 칸인 경우
            dis[nx][ny] = dis[cur.X][cur.Y]+1; 
            Q.push({nx,ny});
        }
    }              
   
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
        if(dis[i][j] == -1){
            cout << -1;
            return 0;
        }else {
            if(res <dis[i][j]) res = dis[i][j];
        }
        }
    }
    cout << res;
}