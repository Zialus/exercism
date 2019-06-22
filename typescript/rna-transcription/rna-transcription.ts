class Transcriptor {

    convertLetter(dnaLetter: string): string {
        switch (dnaLetter) {
            case "A": return "U"
            case "C": return "G"
            case "G": return "C"
            case "T": return "A"
        }

        throw Error("Invalid input DNA.")
    }

    toRna(dnaString: string): string {
        let rnaString = ""
        for (const letter of dnaString) {
            rnaString += this.convertLetter(letter)
        }
        return rnaString
    }
}

export default Transcriptor