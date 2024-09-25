#include <string>
#include <vector>

#include <map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for (auto people: participant) {
        m[people]++;
    }
    
    for (auto people: completion) {
        m[people]--;
    }
    
    for (auto people: participant) {
        if (m[people] != 0) {
            answer = people;
        }
    }
    
    return answer;
}