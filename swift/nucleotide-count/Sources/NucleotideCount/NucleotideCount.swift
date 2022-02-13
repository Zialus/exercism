class DNA {

    enum Nucleotide: Character {
        case adenine = "A", cytosine = "C", guanine = "G", thymine = "T"
    }

    let strand: String

    init?(strand: String) {
        for char in strand {
            if Nucleotide(rawValue: char) == nil {
                return nil
            }
        }
        self.strand = strand
    }

    func count(_ nucleotide: Character) -> Int {
        var count = 0
        for char in self.strand where char == nucleotide {
            count+=1
        }
        return count
    }

    func counts() -> [String: Int] {
        var dict = ["A": 0, "C": 0, "G": 0, "T": 0]
        for char in strand {
            dict[String(char)]! += 1
        }
        return dict
    }
}
