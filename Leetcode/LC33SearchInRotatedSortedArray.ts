// binary search for both the number and pivot point
// so we can find the pivot point by checking the difference between big/small
// but then how do we find the number within?
// let's consider the case
function search(nums: number[], target: number): number {
  let left = 0,
    right = nums.length - 1;

  while (left <= right) {
    const mid = Math.floor((right + left) / 2);

    if (nums[mid] === target) {
      return mid;
    }

    if (nums[left] > nums[mid]) { // right side sorted from mid...right
      if (nums[mid] < target && target <= nums[right]) { // left half contains target
        left = mid + 1;
      } else { // right half contains target
        right = mid - 1;
      }
    } else { // left side sorted from left...mid
      if (nums[left] <= target && target < nums[mid]) { // right half contains target
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
  }

  return -1;
}
