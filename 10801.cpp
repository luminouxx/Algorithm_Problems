#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

//structure of man , include name, age, entered number
struct man
{
public:
    string name;
    int age;
    int enter_num;
    man(string a, int b, int c){ // initializing
        name = a;
        age = b;
        enter_num = c;
    }
};

struct compare{
    bool operator()(man man1 , man man2){
        if(man1.age == man2.age){
            return man1.enter_num > man2.enter_num;
            }
        else{
            return man1.age>man2.age;
        }
    }
};

int enter = 0;
priority_queue<man,vector<man>,compare> pq;


int main(){
    int num;
    cin>> num;
    for(int i = 0 ; i < num ; i++){
        string temp_str;
        int temp_int;
        cin>>temp_int>>temp_str;
        enter++;
        man temp_man(temp_str,temp_int,enter);
        pq.push(temp_man);
    }

    for(int i = 0 ; i < num ; i ++){
        printf("%d %s\n",pq.top().age,pq.top().name.c_str());
        pq.pop();
    }

    return 0;
}