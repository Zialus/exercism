const COLORS_TO_VALUE_MAP = {
  black: 0,
  brown: 1,
  red: 2,
  orange: 3,
  yellow: 4,
  green: 5,
  blue: 6,
  violet: 7,
  grey: 8,
  white: 9,
};

export function decodedValue(bandColors: (keyof typeof COLORS_TO_VALUE_MAP)[]): number {
  let resistanceValue = 0;
  bandColors
    .slice(0, 2)
    .reverse()
    .forEach((color, index) => {
      resistanceValue += COLORS_TO_VALUE_MAP[color] * Math.pow(10, index);
    });

  return resistanceValue;
}
