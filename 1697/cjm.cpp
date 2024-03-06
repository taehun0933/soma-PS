#include<iostream>
#include<algorithm>
#include<queue>
// 주의점 !! 수빈이가 무조건 100000 안에서만 움직인다는 법은 없음! 수빈과 동생이 100000안에 있다고만 했음. 
//그렇다면 수빈이는 최대 200000까지 갔다가 돌아올 수 있음. 물론 굉장히 비효율적인 거리니까 안가겠지만..
//그런 상황이 존재할 수 있다는걸 생각은 할 수 있어야 함

using namespace std;

//일차원 배열의 거리공간에서 움직임
//걷기->1초후에 한칸 앞뒤로 /  순간이동 ->1초후에 현재위치 *2 
//수빈, 동생 위치 주어짐 -> 수빈이가 동생 찾아야되는 데 가장 빠른 시간 언제?
//시작점이 한개이고 도착점 최단으로 도달하는 방법
//둘이 만나면 걸린 시간 출력

int nx[2] = {1,-1};
// int fly_nx = 2; //현재 위치의 2배 앞으로 
int x[100002]; // 전체 위치 배열 
int n,k; // n =수빈
queue<int> Q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n>>k;

    fill(x,x+100002,-1);

    Q.push(n); // 시작점 넣기
    x[n] = 0;

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();

        for(int dir =0;dir<2;dir++){
            int dx = cur + nx[dir];

            if(dx <0 || dx>100000) continue;
            if(x[dx] >= 0) continue; //이미 방문했거나 동생 만난경우
            if(dx == k){ 
                x[dx] = x[cur] +1;
                break;
            }
            Q.push(dx);
            x[dx] = x[cur] +1;
        }

        int dx= cur*2; 

        if(dx <0 ||dx>100000) continue;
        if(x[dx] >= 0) continue;
        if(dx == k){ 
            x[dx] = x[cur] +1;
            break;
        }
        Q.push(dx);
        x[dx] = x[cur] +1;
    }

    cout << x[k];

}