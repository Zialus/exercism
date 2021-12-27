export function isArmstrongNumber(originalNumber: number): boolean {
  const stringRepresentation = originalNumber.toString();
  const size = stringRepresentation.length;
  let armstrongNumber = 0;
  for (const digit of stringRepresentation) {
    const backToNumber = parseInt(digit, 10);
    armstrongNumber += Math.pow(backToNumber, size);
  }

  return armstrongNumber === originalNumber;
}
