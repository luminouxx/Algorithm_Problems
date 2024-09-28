#include <string>
#include <vector>

#include <set>

using namespace std;

int count = 0;

void DFS(int level, int sum, int max, set<int> &s, vector<int> v, int target) {
    if (level == max) {
        if (sum == target) count++;
        return;
    }
    DFS(level+1, sum+v[level], max, s, v, target);
    DFS(level+1, sum-v[level], max, s, v, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    set<int> s;
    
    DFS(0, 0, numbers.size(), s, numbers, target);
    
    answer = count;
    
    return answer;
}