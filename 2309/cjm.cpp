#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v(9);
int result;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<9;i++) {
        cin >> v[i];
        result += v[i];
    }

    for(int i=0;i<8;i++){
        result -= v[i];

        for(int j=i+1; j<9;j++){ 
            result -= v[j];

            if(result == 100) {
                v.erase(v.begin()+i);
                v.erase(v.begin()+j-1);
                
                break;
            }
            
            result += v[j];
            
        }
        if(v.size() != 9) break;
        result += v[i];
    }

    sort(v.begin(),v.end());

    for(int i=0; i<7; i++){
        cout << v[i]<<'\n';
    }

    return 0;
};

