#include<iostream>
#include<algorithm>

using namespace std;

int arr[6];
int result;

int main(){
ios::sync_with_stdio(0);
cin.tie(0);

for(int i=0; i < 5; i++) {
    cin >> arr[i];
    result += arr[i];
}

sort(arr, arr+5);
cout << result / 5 <<'\n'<< arr[2];
return 0;
}