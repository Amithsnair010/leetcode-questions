/*Given a string s, return the longest 
palindromic substring in s.
Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.*/
har * longestPalindrome(char * s){
    int n = strlen(s);
    bool dp[n][n]; // 2D boolean array to store whether substrings are palindromic
    memset(dp, 0, sizeof(dp)); // Initialize dp array with false
    
    int maxLen = 0; // Length of longest palindrome substring
    int start = 0; // Starting index of longest palindrome substring

    // All substrings of length 1 are palindrome
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        maxLen = 1; // Update max length to 1
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            maxLen = 2; // Update max length to 2
            start = i; // Update starting index
        }
    }

    // Check for substrings of length 3 and greater
    for (int k = 3; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1; // Ending index of substring

            // Check if the substring from index i to index j is a palindrome
            if (dp[i + 1][j - 1] && s[i] == s[j]) {
                dp[i][j] = true;
                if (k > maxLen) {
                    maxLen = k; // Update max length
                    start = i; // Update starting index
                }
            }
        }
    }

    // Extract the longest palindrome substring from the input string
    char* result = (char*)malloc(sizeof(char) * (maxLen + 1));
    strncpy(result, s + start, maxLen);
    result[maxLen] = '\0';

    return result;

}
