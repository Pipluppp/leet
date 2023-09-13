int search(int* nums, int numsSize, int target){
    // Copy of pointer to first element
    int *tmp = nums;

    // Clear up trivial cases
    if (target < *nums)
        return -1;
    if (target == *nums)
        return 0;

    while (numsSize > 1) {
        
        // If target might be on the right-hand array, then update nums pointer to mid
        if (target >= nums[numsSize / 2])
            nums += numsSize / 2;
        
        // Halve the array size
        numsSize = numsSize / 2 + (numsSize % 2);
    }

    if (target == *nums)
        return nums - tmp; // Calculates the index by current ptr and orig ptr

    return -1;
}