/*Remove Element ,Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.*/
int removeElement(int* nums, int numsSize, int val) {
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        if (nums[left] == val) {
            // Swap current element with the element at the end of the array
            nums[left] = nums[right];
            right--;
        } else {
            left++;
        }
    }
    // The number of elements not equal to val is the left pointer position
    return left;
}
