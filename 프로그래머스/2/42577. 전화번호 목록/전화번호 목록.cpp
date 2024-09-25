#include <string>
#include <vector>

#include <unordered_map>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> m;
    
    for (auto num1: phone_book) {
        m[num1] = 1;
    }
    
    for (auto num2: phone_book) {
        for (int i=0; i<num2.size()-1; i++) {
            string phone_prefix = num2.substr(0, i+1);
            if (m[phone_prefix]) return false;
        }
    }
    
    return answer;
}