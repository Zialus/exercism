function convertLetter(dnaLetter: string): string {
  switch (dnaLetter) {
    case "A": return "U";
    case "C": return "G";
    case "G": return "C";
    case "T": return "A";
  }

  throw Error("Invalid input DNA.");
}

export function toRna(dnaString: string): string {
  const rnaString = dnaString
    .split("")
    .map((letter) => convertLetter(letter))
    .join("");

  return rnaString;
}
