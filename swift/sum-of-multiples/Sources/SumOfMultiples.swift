func toLimit(_ upTo: Int, inMultiples: [Int]) -> Int {

    var sumCandidates = Set<Int>()

    for number in inMultiples where number > 0 {
        var multiple = number
        // keep adding number to itself and keep track of its multiples
        while multiple < upTo {
            sumCandidates.insert(multiple)
            multiple += number
        }

    }

    return sumCandidates.reduce(0, +)

}
