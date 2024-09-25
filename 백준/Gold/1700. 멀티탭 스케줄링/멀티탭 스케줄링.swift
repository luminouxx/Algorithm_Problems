let input = readLine()!.split(separator: " ").map { Int($0)! }
let (N, K) = (input[0], input[1])

let order: [Int] = readLine()!.split(separator: " ").map { Int($0)! }

var plugs: [Int] = []
var answer: Int = 0

for i in 0..<K {
    let current = order[i]
    // 1. 이미 플러그에 있으면 패스
    if plugs.contains(current) { continue }
    
    // 2. 플러그에 자리 있으면 플러그에 추가
    if plugs.count < N {
        plugs.append(current)
        continue
    }
    
    // 3. 플러그에 자리 없으면, 가장 마지막에 교체되는 제품 교체
    // 교체 대상 : 1. 사용되지 않거나 2.가장 마지막에 교체되는 제품
    var plugsCopy = Set(plugs)
    
    for j in i+1..<K {
        if plugsCopy.count == 1 { break }
        if plugsCopy.contains(order[j]) {
            plugsCopy.remove(order[j])
        }
    }
    // 2개 이상 남을 경우 아무거나 없애도 됨
    plugs.remove(at: plugs.firstIndex(of: plugsCopy.first!)!)
    plugs.append(current)
    answer+=1
}

print(answer)
