/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length

{2, 1, 2};
*/
// sliding window 
// time complexity is O(n) becouse every element we see at once;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int oddCount=0;
        int prevCount =0;
        int result =0;
        int i=0,j=0;

        while(j<n){
            if(nums[j]%2!=0){ // odd
              oddCount++;
              prevCount=0;
            }
            while(oddCount==k){
                prevCount++;
                if(i<n && nums[i]%2==1){
                    oddCount--;
                }
                i++;
            }
            result+=prevCount;
            j++;
        }
        return result;
    }
};

//// hashmap approch
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int, int>mp;

        int result=0;
        int oddCount=0;
        mp[oddCount]=1;

        for(int i=0;i<n;i++){
            oddCount+=(nums[i]%2);
            if(mp.count(oddCount-k)){
                result+=mp[oddCount-k];
            }
            mp[oddCount]++;
        }
        return result;
    }
};