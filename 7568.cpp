#include<iostream>
#include<vector>

using namespace std;

struct person{
    public:
    int height;
    int weight;
    int priority;
    person(int a, int b, int c = 1){
        height = a;
        weight = b;
        priority = c;
    }
};

vector<person> v;

int main(){
    int PersonNum;
    cin>>PersonNum;
    for(int i=0; i<PersonNum; i++){
        int pHeight,pWeight;
        cin>>pWeight>>pHeight;
        person man(pHeight,pWeight);
        v.push_back(man);
    }

    for(int i=0; i<PersonNum; i++){
        for(int j=0; j<PersonNum; j++){
            if((v[i].height<v[j].height)&&(v[i].weight<v[j].weight)){
                v[i].priority ++;
            }
        }
    }

    for(int i=0; i<PersonNum-1; i++){
        cout<<v[i].priority<<' ';
    }
    cout<<v[PersonNum-1].priority;

    return 0;
}