// So, we need to find the minimum amount of change we can make
// We are given an array of coins we can make change with
function coinChange(coins: number[], amount: number): number {
  let values = Array(amount + 1).fill(Infinity); // if at the end, we have value infty at the amount pos, then we are fail
  values[0] = 0;

  for (let i = 1; i <= amount; i++) {
    for (const coin of coins) {
      if (i - coin >= 0) {
        values[i] = Math.min(values[i], values[i - coin] + 1);
      }
    }
  }

  if (values[amount] === Infinity) {
    return -1;
  } else {
    return values[amount];
  }
}
