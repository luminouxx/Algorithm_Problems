#include<iostream>

using namespace std;

int apartment[15][15] ={ };

int main()
{
    for(int i=0; i<15; i++){
        apartment[0][i] = i+1;
    }
    for(int i=1; i<15; i++){
        for(int j=0; j<15; j++){
            int sum = 0;
            for(int k=0; k<=j; k++){
                sum+=apartment[i-1][k];
            }
            apartment[i][j] = sum;
        }
    }

    int number;
    cin>>number;

    for(int i=0; i<number; i++){
        int x,y;
        cin>>x>>y;
        cout<<apartment[x][y-1]<<endl;
    }
    return 0;
}