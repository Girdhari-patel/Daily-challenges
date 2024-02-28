/*
279. Perfect Squares
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer;
 in other words, it is the product of some integer with itself. 
 For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
 

Constraints:

1 <= n <= 104
//
CS IITIAN
youtube
*/
class Solution {
public:
    int arr[10001];
    
    int helper(int n){
        if(n<=0)return 0;
          if(arr[n]!=-1)return arr[n];
        int result=INT_MAX;
        for(int i=1;i<=sqrt(n);i++){
            result =min(result,1+helper(n-i*i) );
        }
        return arr[n]=result;
    }

    int numSquares(int n){
     memset(arr, -1, sizeof(arr));
     return helper(n);
      
    }
};