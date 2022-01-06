#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<string> v;
int n = 0;

//using vector container to store data 
bool cmp(string a, string b){
    if(a.length() == b.length()){
        return a<b;
    }
    else{
        return a.length()<b.length();
    }
}

int main(){
    int num;
    cin>>num;
    
    for(int i = 0 ; i < num; i++){
        string temp_str;
        cin>>temp_str;
        v.push_back(temp_str);
    }

    //using algorithm class : sort, unique
    sort(v.begin(),v.end(),cmp); //sorting
    v.erase(unique(v.begin(),v.end()),v.end()); // erase repeated elements

    int k = v.size();

    for(int i=0 ; i<k ; i++){
        cout<<v[i]<<endl;
    }

    return 0;
}
