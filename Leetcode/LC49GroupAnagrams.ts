// sorting by lexicographical weight is probably easier here but actually implementing it is a pita
function groupAnagrams(strs: string[]): string[][] {
  const maps: Map<
    number,
    Map<string, [number, Map<string, number>]>
  > = new Map();
  for (const str of strs) {
    if (maps.get(str.length)?.has(str)) {
      let val = maps.get(str.length)?.get(str);
      maps.get(str.length)?.set(str, [val![0] + 1, val![1]]);
    } else {
      if (!maps.has(str.length)) {
        maps.set(str.length, new Map());
      }
      const map = new Map();

      for (const c of str) {
        if (!map.has(c)) {
          map.set(c, 1);
        } else {
          map.set(c, map.get(c) + 1);
        }
      }

      maps.get(str.length)?.set(str, [1, map]);
    }
  }

  let groups: string[][] = [];
  for (const [len, submaps] of maps) {
    for (const [str, [count, map]] of submaps) {
      let group: string[] = [];
      for (let i = 0; i < count; i++) group.push(str);
      submaps.delete(str);

      for (const [str2, [count2, map2]] of submaps) {
        let flag = true;
        for (const [key, value] of map2) {
          if (map.get(key) !== value) {
            flag = false;
            break;
          }
        }

        if (flag) {
          submaps.delete(str2);
          for (let i = 0; i < count2; i++) group.push(str2);
        }
      }

      groups.push(group);
    }
  }

  return groups;
}
