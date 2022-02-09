#include<iostream>
#include<deque>
#include<string>

using namespace std;

deque<int> dq;
string strArr[] = {"push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front", "back"};


int main(){

    int num;
    cin>>num;

    for(int i=0; i<num; i++){
        string tempString;
        cin>>tempString;
        int caseNum;
        for(int j=0; j<8; j++){
            if(tempString == strArr[j]){
                caseNum = j;
            }
        }
        int dqNum;
        switch (caseNum){
        case 0:
            scanf("%d",&dqNum);
            dq.push_front(dqNum);
            break;
        case 1:
            scanf("%d",&dqNum);
            dq.push_back(dqNum);
            break;
        case 2:
            if(dq.empty()){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n",dq.front());
                dq.pop_front();
            }
            break;
        case 3:
            if(dq.empty()){
                printf("%d\n", -1);
            }
            else{              
                printf("%d\n",dq.back());
                dq.pop_back();
            }
            break;
        case 4:
            printf("%lu\n",dq.size());
            break;
        case 5:
            if(dq.empty()){
                printf("%d\n",1);
            }
            else{
                printf("%d\n",0);
            }
            break;
        case 6:
            if(dq.empty()){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n",dq.front());
            }
            break;
        case 7:
            if(dq.empty()){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n",dq.back());
            }
            break;
        default:
            break;
        }
    }

    return 0;
}