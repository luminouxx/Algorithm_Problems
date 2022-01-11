#include<iostream>
#include<queue>

using namespace std;

struct coordi{
public:
    int x;
    int y;
    coordi(int a, int b){
        x=a;
        y=b;
    }
};

struct cmp{
    bool operator()(coordi a, coordi b){
        if(a.x==b.x){
            return a.y > b.y;
        }
        else{
            return a.x > b.x;
        }
    }
};

priority_queue<coordi,vector<coordi>,cmp> q;

int main(){
    int num;
    cin>>num;
    for(int i=0; i<num; i++){
        int t_x,t_y;
        cin>>t_x>>t_y;
        coordi t_co(t_x,t_y);
        q.push(t_co);
    }

    for(int i=0; i<num; i++){
        printf("%d %d\n",q.top().x,q.top().y);
        q.pop();
    }
}