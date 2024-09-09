import Foundation

let n = Int(readLine()!)!

var coefficient = [String : Int]()

for _ in 0..<n {
    let sentence = String(readLine()!)
    let sentenceArray = sentence.map { String($0) }
    
    for i in 0..<sentenceArray.count {
        let currentCharacter = sentenceArray[i]
        
        if coefficient[currentCharacter] == nil {
            coefficient[currentCharacter] = Int(pow(10.0, Float(sentenceArray.count-i-1)))
        } else {
            coefficient[currentCharacter]! += Int(pow(10.0, Float(sentenceArray.count-i-1)))
        }
    }
}

let sortedArray = coefficient.sorted { $0.value > $1.value }

var answer = 0
var count = 9

for j in 0..<sortedArray.count {
    answer += sortedArray[j].value * count
    count -= 1
}

print(answer)
