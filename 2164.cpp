#include<iostream>
#include<queue>

using namespace std;

queue<int> q;

int main(){
    int numOfCard = 0;
    cin>>numOfCard;
    for(int i=1; i<=numOfCard; i++){
        q.push(i);
    }

    for(int i=1; i<numOfCard; i++){
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout<<q.front();
    return 0;
}