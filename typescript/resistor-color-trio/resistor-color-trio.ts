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

function convertColorToValue([firstColor, secondColor, lastColor]: (keyof typeof COLORS_TO_VALUE_MAP)[]): number {
  const baseValue = COLORS_TO_VALUE_MAP[firstColor] * 10 + COLORS_TO_VALUE_MAP[secondColor];

  const trailingZeros = Math.pow(10, COLORS_TO_VALUE_MAP[lastColor]);

  return baseValue * trailingZeros;
}

export function decodedResistorValue([
  firstColor,
  secondColor,
  lastColor,
]: (keyof typeof COLORS_TO_VALUE_MAP)[]): string {
  const resistanceValue = convertColorToValue([firstColor, secondColor, lastColor]);

  return resistanceValue > 1000 ? `${resistanceValue / 1000} kiloohms` : `${resistanceValue} ohms`;
}
