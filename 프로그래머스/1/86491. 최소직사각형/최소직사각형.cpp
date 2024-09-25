#include <string>
#include <vector>

#include <algorithm>

using namespace std;

// 한쪽의 길이를 고정해서 최대로 만들고, 다른 한쪽은 최소로
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int height=0; // 높이
    int width=0; // 가로
    
    for(int i=0;i<sizes.size();i++)
    {
        if(sizes[i][0]>sizes[i][1])
        {
            height=max(height,sizes[i][0]);
            width=max(width,sizes[i][1]);
        }
        else
        {
            height=max(height,sizes[i][1]);
            width=max(width,sizes[i][0]);
        }

    }
    
    answer=height*width;
    return answer;
}