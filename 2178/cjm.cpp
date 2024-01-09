#include<iostream>
#include<algorithm> //fill 함수, utility 헤더도 포함됨 - pair 사용 
#include<queue>

using namespace std;
//https://velog.io/@gogori6565/BOJC-%EB%B0%B0%EC%97%B4-%ED%8A%B9%EC%A0%95-%EA%B0%92%EC%9C%BC%EB%A1%9C-%ED%95%9C-%EB%B2%88%EC%97%90-%EC%B4%88%EA%B8%B0%ED%99%94%ED%95%98%EB%8A%94-%EB%B2%95
//거리같은 경우는 -1 등으로 따로 초기화 해주기 
//이중포문 or fill()  
int digst[102][102]; // 거리 저장할 배열

int board[102][102]; // 입력값 저장할 배열
int vis[102][102];

//define 뒤에는 땀흘리지말것
#define X first
#define Y second

int n,m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<pair<int,int>> Q; 
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    cin >> n>>m;

    
    for(int i=0;i<n;i++){
        string a;
        cin >> a;
        
        for(int j=0;j<m;j++){
            int c = a[j] - '0'; //char -> int 해줄때 아스키코드 0 빼줄것 
            board[i][j] =c;

        }
        fill(digst[i],digst[i]+m,-1); //fill 함수를 이용한 값 초기화 

    }

    vis[0][0] =1;
    digst[0][0]=1;
    Q.push({0,0});

    while(!Q.empty()){
        pair<int,int> cur = Q.front();
        Q.pop();

        for(int i = 0; i<4; i++){
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if(nx<0 || nx>=n || ny <0 || ny >=m) continue;
            if(vis[nx][ny] || board[nx][ny] != 1) continue;

            //bfs 는 먼저 도달한 값이 가장 최단거리 값이므로 같은 목적지에 두번 이상 방문할 것이라는 예외처리 필요없음
            digst[nx][ny] = digst[cur.X][cur.Y]+1;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }

    cout << digst[n-1][m-1];
    return 0;
}