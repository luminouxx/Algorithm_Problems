#include<iostream>
#include<cstring>
#include<climits>

using namespace std;


int map[500][500]={};
int row,col;
int Max = 0;
int Min = 256;
int MyBlock = 0;

int CalculateTime(int h){ //if you give height calculate cost by using this function
    int Block = MyBlock; // copy the number of block when inputed in main
    int temp_time = 0; // variable stored cost
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            int height = map[i][j] - h;
            if(height>0){
                temp_time = temp_time + height*2;
                Block = Block + height;
            }
            else{
                temp_time = temp_time - height;
                Block = Block + height;
            }
        }
    }
    if(Block<0){return INT_MAX;} // if this calculation has minus blocks it is false
    return temp_time;
}


int main(){
    cin>>row>>col;
    cin>>MyBlock;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>map[i][j];
            if(map[i][j]>Max){
                Max = map[i][j];
            }
            if(map[i][j]<Min){
                Min = map[i][j];
            }
        }
    }

    int BestTime = INT_MAX;
    int BestHeight = 0;

    for(int i=Min ; i<=Max; i++){ // find every possible height (Min to Max)
        int t = CalculateTime(i);
        if(BestTime >= t){ //update best solution
            BestTime = t;
            BestHeight = i;
        }
    }
    cout<<BestTime<<' '<<BestHeight;


    return 0;
}