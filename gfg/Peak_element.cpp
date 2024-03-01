/*Given an 0-indexed array of integers arr[] of size n, find its peak element. An element is considered to be peak if it's value is greater than or equal to the values of its adjacent elements (if they exist).

Note: The output will be 1 if the index returned by your function is correct; otherwise, it will be 0.

Example 1:

Input: 
n = 3
arr[] = {1, 2, 3}
Peak element's index: 2
Output: 
1
Explanation: 
If the index returned is 2, then the output printed will be 1. Since arr[2] = 3 is greater than its adjacent elements, and there is no element after it, we can consider it as a peak element. No other index satisfies the same property.
Example 2:

Input:
n = 7
arr[] = {1, 1, 1, 2, 1, 1, 1}
Output: 
1
Explanation: 
In this case there are 5 peak elements with indices as {0,1,3,5,6}. Returning any of them will give you correct answer.
Your Task:
You don't have to read input or print anything. Complete the function peakElement() which takes the array arr[] and its size n as input parameters and return the index of the peak element.

Expected Time Complexity: O( log(n) ).
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 106
*/
 class Solution
{
public:
//     int peakElement(int arr[], int n)
//     {
       
//         if (n == 1)
//             return 0;

//         for (int i = 0; i < n; i++)
//         {      
//             if (i == 0)
//             {
//                 if (arr[i] >= arr[i + 1])
//                     return i;
//             }
//             else if (i == n - 1)
//             {
//                 if (arr[i] >= arr[i - 1])
//                     return i;
//             }
//             else
//             {
//                 if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
//                     return i;
//             }
//         }

//         // If no peak element is found, return -1.
//         return -1;
//     }
// };

int peakElement(int arr[], int n)
    {
       //edge case
        if (n == 1)
            return 0;
        int low = 0;
        int high = n - 1;
        
        // Perform binary search to find a peak element.
        while (low < high) {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] >= arr[mid + 1])
                high = mid;
            else
                low = mid + 1;
        }
        return low;
        
    }
};