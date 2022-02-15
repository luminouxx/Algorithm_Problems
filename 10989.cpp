#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin>>num;

    int arr[10001]={0};
    

    for(int i=0; i<num; i++){
        int tempNum;
        cin>>tempNum;
        arr[tempNum]++;
    }

    for(int i=0; i<10001; i++){
        for(int j=0; j<arr[i]; j++){
            cout<<i<<'\n';
        }
    }

    return 0;
}