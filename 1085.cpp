#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;    
    v.push_back(a);
    v.push_back(b);
    v.push_back(c-a);
    v.push_back(d-b);

    sort(v.begin(),v.end());
    cout<<v[0];

    return 0;
}