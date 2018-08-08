enum TranscriptionError: Error {
    case invalidNucleotide(message: String)
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

        for maybeNucleotide in dnaString {
            guard let nucleotide = DnaNucleotide(rawValue: maybeNucleotide) else {
                throw TranscriptionError.invalidNucleotide(message: "\(maybeNucleotide) is not a valid Nucleotide")
            }
            dnaStrand.append(nucleotide)
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
