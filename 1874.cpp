#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<int> s;
string store_op;

int count = 1;
int max_num = 0;

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    int *com_arr = new int[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //make operand string 
    //ex) 43687521 -> "++++--++-++-----"

    for(int i=0; i<n; i++){
        int temp = arr[i];
        if(temp > max_num){
            for(int j=0; j < temp-max_num; j++){
                store_op.append("+");
            }
            store_op.append("-");
            max_num = temp;
        }
        else{
            store_op.append("-");
        }
    }

    //operand String -> stack operation -> storing result

    int cnt = 0;
    int idx = 0;
    for(int i=0; i<store_op.length(); i++){
        if(store_op[i]=='+'){
            cnt++;
            s.push(cnt);
        }
        else{
            com_arr[idx] = s.top();
            s.pop();
            idx++;
        }
    }

    string st1;
    string st2;

    for(int i=0; i<n; i++){
        st1.append(to_string(arr[i]));
        st2.append(to_string(com_arr[i]));
    }

    if(st1 == st2){
        for(int i=0; i<store_op.length(); i++){
            //cout<<store_op[i]<<endl;
            printf("%c\n",store_op[i]);
        }
    }
    else{
        cout<<"NO";
    }

    return 0;
}