import Foundation

class Raindrops {

    let number: Int

    init(_ number: Int) {
        self.number = number
    }

    func findSomeFactors() -> [Int] {
        let candidates = [3, 5, 7]
        return candidates.filter { number % $0 == 0 }
    }

    var sounds: String {
        var answer = ""
        let factors = findSomeFactors()

        if factors.contains(3) { answer += "Pling" }
        if factors.contains(5) { answer += "Plang" }
        if factors.contains(7) { answer += "Plong" }

        if answer.isEmpty {  // if no factors were found, just print the number
            return String(number)
        } else {
            return answer
        }
    }
}
