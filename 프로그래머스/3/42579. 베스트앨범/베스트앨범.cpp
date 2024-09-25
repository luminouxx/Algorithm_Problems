#include <string>
#include <vector>

#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp (pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool cmp2 (pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> m;
    map<string, vector<pair<int, int>>> s;
    
    // 1. 장르별로 정렬, 장르별로 해당 곡 저장.
    for (int i=0; i<genres.size(); i++) {
        m[genres[i]] += plays[i];
        s[genres[i]].push_back({plays[i], i});
    }
    
    // 2. 벡터에 복사
    vector<pair<string, int>> v;
    for (auto temp: m) {
        v.push_back({temp.first, temp.second});
    }
    
    // 3. 벡터 정렬
    sort(v.begin(), v.end(), cmp);
    
    // 4. 정렬 순서에 맞게 answer에 추가
    for (auto t: v) {
        vector<pair<int, int>> cur = s[t.first];
        
        sort(cur.begin(), cur.end(), cmp2);
        
        if (cur.size() == 1) {
            answer.push_back(cur[0].second);
        } else {
            for (int i=0; i<2; i++) {
                answer.push_back(cur[i].second);
            }
        }
    }
    
    return answer;
}