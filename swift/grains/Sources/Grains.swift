import Foundation

enum GrainsError: Error {
    case inputTooLow(message: String)
    case inputTooHigh(message: String)
}

// For the "powers of two math" to be valid, cell's index must start at 0,
// thefore we need to subtract 1 from the cell number
func square(_ cell: Int) throws -> Double {
    guard cell > 0 else {
        throw GrainsError.inputTooLow(message: "Input[\(cell)] invalid. Input should be between 1 and 64 (inclusive)")
    }

    guard cell < 65 else {
        throw GrainsError.inputTooHigh(message: "Input[\(cell)] invalid. Input should be between 1 and 64 (inclusive)")
    }

    let num = cell - 1
    return pow(2, Double(num))
}

// Sums the ammount of grains in all cells up to a given cell (not inclusive)
// Each cell has the same amount of grains as all previous cells combined, plus 1
func sum(upTo cell: Double) -> Double {
    let num = cell - 1
    return pow(2, num) - 1
}

let total = sum(upTo: 65)
