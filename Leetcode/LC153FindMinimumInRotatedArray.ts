// go to right if the end is smaller than the start
function findMin(nums: number[]): number {
  let left = 0,
    right = nums.length - 1;

  // exit condition: check if we converge
  while (left < right) {
    const mid = left + Math.floor((right - left) / 2);
    if (nums[mid] > nums[right]) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return nums[left];
}
