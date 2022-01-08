#include<iostream>

using namespace std;

int main(){
    int num = 0;
    cin>>num;
    
    int i = 1;
    int level = 1;
    int Need_level = 1;

    while(num>Need_level){
        num = num - Need_level;
        Need_level = 6*i;
        i++;
        level++;
    }

    cout<<level;

    return 0;
}