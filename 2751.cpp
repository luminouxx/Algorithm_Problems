#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int main(){
    int num;
    cin>>num;

    for(int i=0; i <num; i++){
        int t_num;
        cin>>t_num;
        v.push_back(t_num);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i=0; i<v.size(); i++){
        printf("%d\n",v[i]);
    }

    return 0;
}