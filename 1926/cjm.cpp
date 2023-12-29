#include<iostream>
#include<utility>
#include<queue>

using namespace std;
int n,m;

#define X first
#define Y second

queue<pair<int,int>> Q;
int dx[4] = {1,0,-1,0}; // 행 
int dy[4] = {0,1,0,-1}; //열 

int board[502][502];
bool vis[502][502];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>n>>m;

    for(int i=0; i<n; i++){ // 이차원 배열 board 생성
        for(int j=0;j<m;j++){
            int c;
            cin >> c;
            board[i][j] = c;
        }
    }
    
    int max =0;
    int now =0;
    int num =0;

     for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] || board[i][j] != 1) continue;
            Q.push({i,j});
            vis[i][j] =1;
            
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); 
                Q.pop();
                now++;

                for(int i =0; i<4;i++){
                    int nx = cur.X + dx[i];
                    int ny = cur.Y + dy[i];
                    if(nx <0 || nx>n||ny<0||ny>m) continue;
                    if(vis[nx][ny] || board[nx][ny] != 1) continue;
                    
                    vis[nx][ny] = 1;
                    
                    Q.push({nx,ny});
                }
            }
            if(max < now) max = now; 
            num++;
            now =0;
        }
    }
    cout << num << '\n'<<max;
    return 0;
}