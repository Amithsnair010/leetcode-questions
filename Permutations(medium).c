/*Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    void swap(int* a, int* b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void generatePermutations(int* nums, int start, int end, int** result, int* returnSize, int** returnColumnSizes) {
        if (start == end) {
            // Append the current permutation to the result array
            result[*returnSize] = (int*)malloc(sizeof(int) * (end + 1));
            memcpy(result[*returnSize], nums, sizeof(int) * (end + 1));
            (*returnColumnSizes)[*returnSize] = end + 1;
            (*returnSize)++;
        } else {
            for (int i = start; i <= end; i++) {
                swap(&nums[start], &nums[i]);
                generatePermutations(nums, start + 1, end, result, returnSize, returnColumnSizes);
                swap(&nums[start], &nums[i]); // Backtrack
            }
        }
    }

    // Calculate the total number of permutations
    int totalPermutations = 1;
    for (int i = 1; i <= numsSize; i++) {
        totalPermutations *= i;
    }

    // Allocate memory for the result array and column sizes array
    int** result = (int**)malloc(sizeof(int*) * totalPermutations);
    *returnColumnSizes = (int*)malloc(sizeof(int) * totalPermutations);
    *returnSize = 0;

    // Generate permutations
    generatePermutations(nums, 0, numsSize - 1, result, returnSize, returnColumnSizes);

    return result;
}
