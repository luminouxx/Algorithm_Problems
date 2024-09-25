#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 정렬 custom 해야 함
bool cmp (string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> temp;
    for (auto num: numbers) {
        temp.push_back(to_string(num));
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    for (int i=0; i<temp.size(); i++) {
        answer += temp[i];
    }
    if (temp[0] == "0") return "0";
    
    return answer;
}