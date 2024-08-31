let input = readLine()!.split(separator: " ").map { Int($0)! }

let n = input[0]
let k = input[1]

var coins =  [Int]()

for _ in 0..<n {
    coins.append(Int(readLine()!)!)
}

var dp = [Int](repeating: 0, count: k+1)

dp[0] = 1

for coin in coins {
    if coin <= k {
        for idx in coin...k {
            dp[idx] += dp[idx-coin]
            
            // Swift는 오버플로우 시 에러 반환하므로, 직접 처리해줘야함
            if dp[idx] >= 2147483648 {
                dp[idx] = 0
            }
        }
    }   
}

print(dp[k])
