#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
//1을 찾아서 시작점으로
//최소 개수- > bfs
/////행 열 입력이 반대였는데 빨리풀다가 발견 못하고..........쓸데없이 오래 해멘.... 문제를 잘 읽자 ! 예시의 입력값을 잘 보자, 가로길이 세로길이 그림으로 그려두자
#define X first
#define Y second

int k; // 심어진 배추 개수
int t,m,n; // 테스트케이스 개수
queue<pair<int,int>> Q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){ // board 랑 vis 를 테스트 케이스마다 초기화 해줘야되는 것을 간과함
        int board[52][52]={0 ,}; // 배추 위치 담음
        bool vis[52][52]={0 ,};//방문 여부 확인 => bool 형식으로 할것

        int result =0;
        cin >> m>>n>>k;
        // m = 행 , n = 열
        for(int i = 0;i<k;i++){
            int x, y;
        cin >> x >> y;
            board[y][x] = 1; // 배추 위치에 1을 심어줌
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j]==1 && vis[i][j] == 0){ //방문 안한 배추 발견시
                    result++;
                    vis[i][j] =1;
                    Q.push({i,j});
                    while(!Q.empty()){ //큐가 비어있는게 아닌경우
                        pair<int,int> cur = Q.front(); 
                        Q.pop(); //pop하는거 까먹고 안써줬당 주의주으이
                        for(int k = 0; k<4;k++){
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k]; 
                            
                            if(nx<0|| nx>=n|| ny <0||ny>=m) continue; // m = 가로길이 = 열개수 
                            if(vis[nx][ny]==1|| board[nx][ny] ==0) continue; //board 가 배추가 아닌경우 continue 하는거임
                            
                            vis[nx][ny]=1;
                            Q.push({nx,ny});
                        }
                    } 
                }
            }
        }
        cout << result<<'\n';
    }
}