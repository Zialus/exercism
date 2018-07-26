import Foundation

class Squares {
    let upTo: Int

    init(_ upTo: Int) {
        self.upTo = upTo
    }

    var squareOfSums: Decimal {
        var tmp = 0
        for num in 1...upTo {
            tmp += num
        }
        return pow(Decimal(tmp), 2)
    }

    var sumOfSquares: Decimal {
        var result: Decimal = 0
        for num in 1...upTo {
            result += pow(Decimal(num), 2)
        }
        return result
    }

    var differenceOfSquares: Decimal {
        return squareOfSums - sumOfSquares
    }
}
