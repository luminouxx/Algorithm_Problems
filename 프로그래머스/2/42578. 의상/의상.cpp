#include <string>
#include <vector>

#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    map<string, int> m;
    
    for (auto cloth: clothes) {
        m[cloth[1]]++;
    }
    
    for (auto temp: m) {
        answer *= (temp.second+1);
    }
    
    answer--;
    
    return answer;
}