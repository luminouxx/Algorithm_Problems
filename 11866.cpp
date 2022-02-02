#include<iostream>
#include<queue>

using namespace std;

queue<int> q;

int main(){
    int num;
    cin>>num;

    int order;
    cin>>order;

    for(int i=1 ; i<=num; i++){
        q.push(i);
    }

    cout<<"<";
    while(!q.empty()){
        for(int i=1; i<order; i++){
            q.push(q.front());
            q.pop();
        }
        if(q.size()!=1){
            cout<<q.front()<<", ";
            q.pop();
        }
        else{
            cout<<q.front();
            q.pop();
        }
    }    
    cout<<">";

    return 0;
}