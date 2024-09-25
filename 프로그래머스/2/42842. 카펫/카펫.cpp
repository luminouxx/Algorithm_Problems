#include <string>
#include <vector>

#include <cmath>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int total_length = brown + yellow;
    
    vector<int> width;
    vector<int> height;
    
    for (int i=3; i<=sqrt(total_length); i++) {
        if (total_length%i == 0) {
            height.push_back(i);
            width.push_back(total_length / i);
        }
    }
    
    for (int i=0; i<width.size(); i++) {
        if ((width[i]-2) * (height[i]-2) == yellow) {
            answer.push_back(width[i]);
            answer.push_back(height[i]);
            break;
        }
    }
    
    return answer;
}