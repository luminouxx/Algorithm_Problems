#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++) {
        vector<int> temp;
        vector<int> cur_commands = commands[i];
        
        int start = cur_commands[0];
        int end = cur_commands[1];
        int rank = cur_commands[2];
        
        for (int j=start-1; j<end; j++) {
            temp.push_back(array[j]);
        }
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[rank-1]);
    }
    
    return answer;
}