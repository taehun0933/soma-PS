#include<iostream>
#include<vector>

using namespace std;

int N;
int arr[10001]={50,42};

int func2(int arr[], int N) {
    vector<int> ref(10001, 0);
    // sort(arr,arr+10001);

    for (int i=0; i<N; i++){
        ref[100-arr[i]]++;
    }

    for (int i=0; i<N; i++){
        if(arr[i]==50 && ref[100-arr[i]]>1) return 1;
        if(arr[i]!=50 && ref[100-arr[i]] != 0) return 1;
        
        return 0;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << func2(arr,2);
    // cout << func2(arr,2);
    // cout << func2(arr,4);

};