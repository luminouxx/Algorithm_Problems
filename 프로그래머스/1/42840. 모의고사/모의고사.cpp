#include <string>
#include <vector>

#include <algorithm>

using namespace std;

int one[] = { 1, 2, 3, 4, 5 };
int two[] = { 2, 1, 2, 3, 2, 4, 2, 5 };
int three[] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    
    for (int i=0; i<answers.size(); i++) {
        if (answers[i] == one[i%5]) count1++;
        if (answers[i] == two[i%8]) count2++;
        if (answers[i] == three[i%10]) count3++;
    }
    
    int max_value = max(count1, max(count2, count3));
    
    if (count1 == max_value) answer.push_back(1);
    if (count2 == max_value) answer.push_back(2);
    if (count3 == max_value) answer.push_back(3);
    
    return answer;
}