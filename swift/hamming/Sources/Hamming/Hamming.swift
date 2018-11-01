func compute(_ someDNA: String, against otherDNA: String) -> Int? {

    guard someDNA.count == otherDNA.count else {
        return nil
    }

    var count = 0
    for (someLetter, otherLetter) in zip(someDNA, otherDNA) where someLetter != otherLetter {
        count += 1
    }

    return count
}
