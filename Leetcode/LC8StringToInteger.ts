function myAtoi(s: string): number {
  let split = s.trim().split("");
  if (!split.length) return 0;
  let output = 0;
  let polarity = 1;
  if (split[0] === "-") {
    polarity = -1;
  } else if (48 <= split[0].charCodeAt(0) && split[0].charCodeAt(0) <= 57) {
    output = split[0].charCodeAt(0) - 48;
  } else if (split[0] !== "+") {
    return output;
  }

  for (let i = 1; i < split.length; i++) {
    const c = split[i];
    if (48 > c.charCodeAt(0) || c.charCodeAt(0) > 57) {
      break;
    }

    output *= 10;
    output += c.charCodeAt(0) - 48;
  }

  return Math.max(Math.min(output * polarity, 2147483647), -2147483648);
}
