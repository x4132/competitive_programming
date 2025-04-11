int removeDuplicates(int *nums, int numsSize) {
    int index, shiftIndex, temp, sortedSize = numsSize;
    int sortedSize = numsSize;

    for (index = 1; index < sortedSize; index++) {
        if (nums[index - 1] == nums[index]) {
            temp = nums[index];
            for (shiftIndex = index + 1; shiftIndex < numsSize; shiftIndex++) {
                nums[shiftIndex - 1] = nums[shiftIndex];
            }
            sortedSize--;
            nums[numsSize - 1] = temp;
            index--;
        }
    }

    return numsSize;
}
