#include<iostream>
#include<queue>
using namespace std;

int n;
queue<int> card;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i =1;i<n+1;i++){
        card.push(i);
    }

    while(card.size()>1){
        card.pop();
        
        int toBottom = card.front();
        card.pop();
        card.push(toBottom);
        
    }

    cout << card.front();
    
}