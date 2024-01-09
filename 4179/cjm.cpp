#include<iostream>
#include<queue>
#include<algorithm>
// 서로 다른 시작점이 존재하는데, 그 두 시작점이 서로에게 영향을 끼치는 상황. 즉 동시에 진전해야하는 상황이라면 불먼저 bfs를 도는 방법은 사용 불가능함.
using namespace std;

#define X first
#define Y second

queue<pair<int,int>> fire;
queue<pair<int,int>> ji;

int dis[1002][1002]; //#, J, F=0 // .은 -1
int jdis[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int r,c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>r>>c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char maze;
            cin >> maze;
            if(maze == '.'){
                dis[i][j] = -1;
                jdis[i][j] = -1;
            }else if(maze == 'F') {
                fire.push({i,j});
            }else if(maze == 'J') ji.push({i,j});
        }
    }

    while(!fire.empty()){
        pair<int,int> cur = fire.front(); 
        fire.pop();
        for(int dir =0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx>=r||nx<0||ny>=c||ny<0) continue;
            if(dis[nx][ny] >= 0) continue;

            dis[nx][ny] = dis[cur.X][cur.Y] +1;
            fire.push({nx,ny});
        }
    }
    
    //dis[nx][ny]는 불이 지나간 시점을 담은 것 . 즉 이미 담긴 값보다 현재 값이 작아야 지훈이는 탈출 가능한 것
    while(!ji.empty()){
        pair<int,int> cur = ji.front(); 
        ji.pop();

        for(int dir =0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx>=r||nx<0||ny>=c||ny<0){
                // 다음칸이 가장자리인데 이때 현재의 dis 값이 지훈이가 더 작은 경우 -> 지훈이가 불보다 먼저도착-> 탈출
                if(jdis[cur.X][cur.Y] < dis[cur.X][cur.Y] || dis[cur.X][cur.Y] == -1 || jdis[cur.X][cur.Y] == 0){
                    cout << jdis[cur.X][cur.Y]+1;
                    return 0;
                }
                continue;
            }
            if(jdis[nx][ny] >= 0) continue; //#, J, F 인 경우에는 다른 칸으로
            
            jdis[nx][ny] = jdis[cur.X][cur.Y] +1;
            ji.push({nx,ny});
        }
    }

    cout << "IMPOSSIBLE";
    return 0;
}   