#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int MAXN = 100001;
int arr[MAXN];
vector<int> minTree,maxTree;

int N,M;

//initializing segment Tree
void init(int node, int start, int end){
    if(start == end){ //if it is leaf node
        minTree[node] = maxTree[node] = arr[start];
        return;
    }
    else{ //recursion
        init(node*2,start,(start+end)/2); 
        init(node*2+1,(start+end)/2 + 1 ,end);
        minTree[node] = min(minTree[node*2],minTree[node*2+1]);
        maxTree[node] = max(maxTree[node*2],maxTree[node*2+1]);
        return;
    }
}

pair<int,int> findMinMax(int node, int start, int end, int left, int right){
    if (left>end || right<start){ //겹치는 부분 없음
        return make_pair(INT32_MAX,0);
    }
    else if(left<=start && end <= right){ //해당 노드 값 리턴
        return make_pair(minTree[node],maxTree[node]);
    }
    else{ //recursion case
        pair<int,int> leftchild, rightchild;
        leftchild = findMinMax(node*2, start, (start+end)/2, left, right);
        rightchild = findMinMax(node*2+1, (start+end)/2+1, end, left, right);
        return make_pair(min(leftchild.first,rightchild.first),max(leftchild.second,rightchild.second));
    }
    

}

int main(){

    scanf("%d %d", &N, &M);

    int heihgt = (int)ceil(log2(N));
    int Idx = pow(2,heihgt+1);

    minTree = vector<int>(Idx);
    maxTree = vector<int>(Idx);

    for(int i=1; i<=N; i++){
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
    }

    init(1,1,N);
    pair<int,int> result;
    
    for(int i=0; i<M; i++){
        int left,right;
        scanf("%d %d",&left,&right);
        result = findMinMax(1,1,N,left,right);
        printf("%d %d\n",result.first,result.second);
    }
    return 0;
}