#include<iostream>
#include<string>

using namespace std;

int main(){

    string str;
    while(true){
        cin>>str;
        int len = str.length();
        if(str == "0"){
            break;
        }
        else{
            if(len%2==0){
                int start = 0;
                int end = len-1;
                while(true){
                    if(str[start]!=str[end]){
                        cout<<"no"<<endl;
                        break;
                    }
                    if(end==start+1){
                        if(str[start]==str[end]){
                            cout<<"yes"<<endl;
                            break;
                        }
                        else{
                            cout<<"no"<<endl;
                        }
                    }
                    start++;
                    end--;
                }
            }
            else{
                int start = 0;
                int end = len-1;
                while(true){
                    if(str[start]!=str[end]){
                        cout<<"no"<<endl;
                        break;
                    }
                    if(end==start){
                        cout<<"yes"<<endl;
                        break;
                    }
                    start++;
                    end--;
                }
            }

        }
    }


    return 0;
}