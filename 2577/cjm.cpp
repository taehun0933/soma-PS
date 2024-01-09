#include<iostream>
#include<string>
using namespace std;

int a,b,c;
string result;
int num[10];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>a >>b>>c;

    result =to_string(a*b*c);

    for(int i =0; i<result.length();i++){
        int toInt = result[i] - '0';
        num[toInt]++;
    }

    for(int i : num){
        cout << i <<"\n";
    }

    return 0;

}