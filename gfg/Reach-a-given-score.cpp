/*Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

Example 1:

Input
n = 10
Output
2
Explanation
There are two ways {5,5} and {10}.
Example 2:

Input
n = 20
Output
4
Explanation
There are four possible ways. {5,5,5,5}, {3,3,3,3,3,5}, {10,10}, {5,5,10}.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function count( ) which takes n as input parameter and returns the answer to the problem.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:

1 ≤ n ≤ 106

https://www.youtube.com/watch?v=IcD5QP4hNr8 youtube channal
*/
// class Solution
// {
//     public:
//     // Complete this function
//   void solve(int n, long long &count){
     
//         if(n==0){
//             count++;
          
//         }
//           if(n<=3){
//             return;
//         }
//         solve(n-3, count);
//         solve(n-5, count);
//         solve(n-10, count);
//     }
//     long long int count(long long int n)
//     {
//     	// Your code here
//       long long count;	
//       solve(n, count);
//       return count;
//     }
// };
class Solution
{
    public:
    // Complete this function
   
    long long int count(long long int n)
    {
    	// Your code here
      vector<long long>v(n+1, 0);
      v[0]=1;
      
      for(int i=3;i<=n;i++){
          v[i]+=v[i-3];
      }
      
       for(int i=5;i<=n;i++){
          v[i]+=v[i-5];
      }
      
       for(int i=10;i<=n;i++){
          v[i]+=v[i-10];
      }
      
      return v[n];
    }
};