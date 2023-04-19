/*Given an integer x, return true if x is a 
palindrome, and false otherwise.
Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.*/
bool isPalindrome(int u){
    long int t,sum=0;
    int x=u;
    while(x>0){
        t=x%10;
        sum=sum*10+t;
        x/=10;
    }
    if(sum==u){
        return true;
    }else{
        return false;
    }
}
