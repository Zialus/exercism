object Hamming {

    fun compute(leftStrand: String, rightStrand: String): Int {
        if (leftStrand.length != rightStrand.length) {
            throw IllegalArgumentException("left and right strands must be of equal length")
        }

        var distance = 0

        for ((leftChar, rightChar) in leftStrand.zip(rightStrand)) {
            if (leftChar != rightChar) {
                distance += 1
            }
        }

        return distance
    }
}
