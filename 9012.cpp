#include<iostream>
#include<stack>
#include<string>

using namespace std;

string findYes(string temp){
    string result;
    stack<string> s;
    for(int i=0; i<temp.length(); i++){
        if(temp[i]=='('){
            s.push("(");
        }
        else if(temp[i]==')'){
            if(s.empty()){
                result = "NO";
                return result;
                break;
            }
            else{
                s.pop();
            }
        }
    }
    if(s.empty()){
        result = "YES";
        return result;    
    }
    else{
        result = "NO";
        return result;
    }
}

int main(){

    int num;
    cin>>num;

    for(int i=0; i<num; i++){
        string temp;
        cin>>temp;
        cout<<findYes(temp)<<endl;
    }

    return 0;
}