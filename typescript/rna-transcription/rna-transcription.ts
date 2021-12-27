class Transcriptor {
  convertLetter(dnaLetter: string): string {
    switch (dnaLetter) {
      case "A": return "U";
      case "C": return "G";
      case "G": return "C";
      case "T": return "A";
    }

    throw Error("Invalid input DNA.");
  }

  toRna(dnaString: string): string {
    const rnaString = dnaString.split('').map(letter => this.convertLetter(letter)).join('');
    
    return rnaString;
  }
}

export default Transcriptor;
