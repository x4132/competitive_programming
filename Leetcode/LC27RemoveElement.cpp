// this is actually c


int removeElement(int* nums, int numsSize, int val) {
    short index;
    short newIndex = 0;

    for (index = 0; index < numsSize; index++) {
        if (nums[index] != val) {
            nums[newIndex] = nums[index];

            newIndex++;
        }
    }

    return newIndex;
}
