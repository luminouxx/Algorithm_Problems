#include<iostream>

using namespace std;

int MAX = 2500;

int StartBlack(char **map,int row,int col){
    int NeedRedraw = 0;
    for(int i=row; i<row+8 ; i++){
        for(int j=col; j<col+8; j++){
            if((i+j)%2 == 0){
                if(map[i][j]!='B'){
                    NeedRedraw++;
                }
            }
            else{
                if(map[i][j]!='W'){
                    NeedRedraw++;
                }
            }
        }
    }
    return NeedRedraw;
}

int StartWhite(char **map,int row,int col){
    int NeedRedraw = 0;
    for(int i=row; i<row+8 ; i++){
        for(int j=col; j<col+8; j++){
            if((i+j)%2 == 0){
                if(map[i][j]!='W'){
                    NeedRedraw++;
                }
            }
            else{
                if(map[i][j]!='B'){
                    NeedRedraw++;
                }
            }
        }
    }
    return NeedRedraw;
}




int main(){
    int row,col;
    cin>>row>>col;

    char **map = new char*[row];

    for(int i=0; i<row; i++){
        map[i] = new char[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>map[i][j];
        }
    }

    for(int i=0; i<row-7; i++){
        for(int j=0; j<col-7; j++){
            int Stblack = StartBlack(map,i,j);
            int Stwhite = StartWhite(map,i,j);
            if(Stblack < MAX){
                MAX = Stblack;
            }
            if(Stwhite < MAX){
                MAX = Stwhite;
            }
        }
    }

    cout<<MAX;

    return 0;
}