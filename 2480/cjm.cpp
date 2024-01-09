#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dice[3];
vector<int> same;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i<3; i++){
        cin >> dice[i];
    }

    for(int i = 0; i<2; i++){
        for(int j =1;j<3;j++){
            if(dice[i] == dice[j]){
                
                if(same.empty()){
                same.push_back(dice[i]);
                same.push_back(dice[j]);
                }else{
                    same.push_back(dice[j]);
                }
                cout <<same[i];

            }
        }
    }
    
    if(same.size() == 2 ){
        cout << 1000+same[0]*100;
    }else if(same.size() == 3){
        cout << '\n'<<10000+same[0]*1000;
    }else {
        cout <<1000;
    };
    return 0;
}