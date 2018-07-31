enum TranscriptionError: Error {
    case invalidNucleotide
}

class Nucleotide {

    enum DnaNucleotide: Character {
        case adenine = "A", cytosine = "C", guanine = "G", thymine = "T"

        var rnaComplement: Character {
            switch self {
            case .guanine:         // G -> C
                return DnaNucleotide.cytosine.rawValue
            case .cytosine:        // C -> G
                return DnaNucleotide.guanine.rawValue
            case .thymine:         // T -> A
                return DnaNucleotide.adenine.rawValue
            case .adenine:         // A -> U
                return "U"
            }
        }

    }

    let dnaStrand: [DnaNucleotide]

    init(_ dnaString: String) throws {
        let dnaStrand = dnaString.flatMap(DnaNucleotide.init(rawValue:))
        // Make sure that all the strings got converted to Nucleotide, or throw error
        if dnaStrand.count != dnaString.count { throw TranscriptionError.invalidNucleotide }

        self.dnaStrand = dnaStrand
    }

    func complementOfDNA() -> String {
        var dnaString = ""

        for nucleotide in dnaStrand {
            dnaString.append(nucleotide.rnaComplement)
        }

        return dnaString
    }

}
