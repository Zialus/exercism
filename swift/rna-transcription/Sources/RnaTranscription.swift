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
        var dnaStrand: [DnaNucleotide] = []

        do {
            for nucleotide in dnaString {
                guard let nuc = DnaNucleotide(rawValue: nucleotide) else {
                    throw TranscriptionError.invalidNucleotide
                }
                dnaStrand.append(nuc)
            }
        }

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
