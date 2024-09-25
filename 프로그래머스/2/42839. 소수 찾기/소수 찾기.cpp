#include <string>
#include <vector>

#include <set>
#include <iostream>
#include <cmath>

using namespace std;

int primes[] = {2, 3, 5, 7};

// 소수 판별 : 에라토스테네스의 해
bool isPrime(int n) {
    if (n < 2) return false;
    
    for (int i=2; i<=sqrt(n); i++) {
        if (n%i == 0) return false;
    }   
    
    return true;
}

set<int> s;

// 조합 만들어서 집합에 집어 넣기
void make_combinations(string prev, string others) {
    
    if (others == "") return;
    
    for (int i=0; i<others.size(); i++) {
        string cur = prev + others[i];
        s.insert(stoi(cur));
        
        make_combinations(cur, others.substr(0, i) + others.substr(i + 1));
    }
}

int solution(string numbers) {
    int answer = 0;
    
    // 1. 조합 만들기
    make_combinations("", numbers);
    
    // 2. 집합 탐색
    for (auto temp : s) {
        cout << temp << ' ' << isPrime(temp) << endl;
        if (isPrime(temp)) answer++;
    }
    
    return answer;
}