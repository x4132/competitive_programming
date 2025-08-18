function isAnagram(s: string, t: string): boolean {
  const map = new Map();

  for (const char of s) {
    if (!map.has(char)) {
      map.set(char, 1);
    } else {
      map.set(char, map.get(char) + 1);
    }
  }

  for (const char of t) {
    if (!map.has(char)) {
      return false;
    } else {
      let count = map.get(char);
      if (count === 1) {
        map.delete(char);
      } else {
        map.set(char, count - 1);
      }
    }
  }

  if (map.size > 0) {
    return false;
  }
  return true;
}
