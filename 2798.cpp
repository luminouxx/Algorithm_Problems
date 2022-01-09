#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> card;
vector<int> s;

int main(){
    int n;
    cin>>n;

    int max;
    cin>>max;

    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        card.push_back(temp);
    }

    for(int i = 0; i < n-2; i++){
        for(int j=i+1; j < n-1; j++){
            for(int k=j+1; k<n; k++){
                int sum = card[i]+card[j]+card[k];
                if(sum<=max){
                    s.push_back(sum);
                }
            }
        }
    }

    sort(s.begin(),s.end());
    s.erase(unique(s.begin(),s.end()),s.end());
    
    int k = s.size();
    cout<<s[k-1];

    return 0;
}