var arr: [[Int]] = []
let dx: [Int] = [0, 0, -1, 1]
let dy: [Int] = [-1, 1, 0, 0]
var M: Int = 0
var N: Int = 0

func BFS() {
    var visited = Array(repeating: Array(repeating: false, count: M), count: N)
    var queue = [(0, 0)]
    var index: Int = 0
    
    visited[0][0] = true
    
    while(true) {
        if (index >= queue.count) {
            break
        }
        
        let cur = queue[index]
        let cur_x = cur.0
        let cur_y = cur.1
        
        
        
        for i in 0..<4 {
            let next_x = cur_x + dx[i]
            let next_y = cur_y + dy[i]
            
            if (next_x<0 || next_x>=M || next_y<0 || next_y>=N) {
                continue
            }
            
            if (arr[next_y][next_x] != 0) {
                arr[next_y][next_x] += 1
            }
            
            if (!visited[next_y][next_x] && arr[next_y][next_x] == 0) {
                queue.append((next_x, next_y))
                visited[next_y][next_x] = true
            }
        }
        
        index += 1
    }
}

func check() -> Bool {
    
    for i in 0..<N {
        for j in 0..<M {
            if arr[i][j] != 0 {
                return false
            }
        }
    }
    return true
}

func meltingCheese() {
    
    for i in 0..<N {
        for j in 0..<M {
            if arr[i][j] > 2 {
                arr[i][j] = 0
            } else if arr[i][j] == 2{
                arr[i][j] = 1
            }
        }
    }
}

func solve() {
    let input = readLine()!.split(separator: " ").map { Int($0)! }
    N = input[0]
    M = input[1]
    
    for _ in 0..<N {
        arr.append(readLine()!.split(separator: " ").map { Int($0)! })
    }
    
    var day: Int = 0
    
    while(!check()) {
        day += 1
        BFS()
        meltingCheese()
    }
    
    print(day)
}

solve()
