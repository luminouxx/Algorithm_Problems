#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int map[20][20]; //물고기 맵
bool visit[20][20]; //BFS를 위한 방문노드 check


//shark구조체 : X좌표,Y좌표,시간 저장
struct shark{
public:
    int sX;
    int sY;
    int sT;
};

int sLevel = 2;
int sEat = 0;
int sTime = 0;

int dx[] = {0,-1,1,0};
int dy[] = {1,0,-0,-1};

//우선순위 정해주기
struct cmp{
    bool operator()(shark a, shark b){
        if(a.sT == b.sT){
            if(a.sX == b.sX){
                return a.sY > b.sY;
            }
            else{
                return a.sX > b.sX;
            }
        }
        else{
            return a.sT > b.sT;
        }
    }
};


int main(){

    int N;
    cin>>N;
    shark s;
    queue<shark> Q;
    

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>map[i][j];
            if (map[i][j]==9){
                s.sX = i;
                s.sY = j;
                Q.push({i,j,0});
                map[i][j] = 0;
                visit[i][j] = true;
            }
        }
    }

    
    while (true)
    {
        priority_queue<shark,vector<shark>,cmp> PQ; //for initializing 
        //BFS를 이용한 갈 수 있는 상어 찾아서, priority_queue에 저장하기
        while(!Q.empty()){
            shark curS = Q.front();
            Q.pop();
            for (int i=0; i<4; i++){
                int curX = curS.sX + dx[i];
                int curY = curS.sY + dy[i];
                if (map[curX][curY]>sLevel||curX<0 || curY<0 || curX>N-1 || curY>N-1){
                    continue;
                }
                if (map[curX][curY]<=sLevel && visit[curX][curY] == false){
                    Q.push({curX,curY,curS.sT+1});
                    visit[curX][curY] = true;
                    if (map[curX][curY]<sLevel && map[curX][curY]!=0){
                        PQ.push({curX,curY,curS.sT+1});
                    }
                }
            }
        }
        
        memset(visit,false,sizeof(visit)); // visit 초기화

        
        if (!PQ.empty()){
            shark topS = PQ.top();
            PQ.pop();
            map[topS.sX][topS.sY] = 0;
            visit[topS.sX][topS.sY] = true;
            sEat ++;
            sTime = topS.sT;           
            Q.push({topS.sX,topS.sY,topS.sT});
        }
        else{
            cout<<sTime;
            break;
        }

        if (sEat == sLevel){
            sEat = 0;
            sLevel++;
        }
    }   

    return 0;
}