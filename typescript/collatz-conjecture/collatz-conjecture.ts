export function steps(n: number): number {
  if (n <= 0) {
    throw Error("Only positive numbers are allowed");
  }

  let num_steps = 0;
  while (n !== 1) {
    if (n % 2 === 0) {
      n = n / 2;
    } else {
      n = 3 * n + 1;
    }
    num_steps += 1;
  }
  return num_steps;
}
