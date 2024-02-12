/*169. Majority Element
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        int maj = NULL;

        for(int i=0;i<n;i++){
            if(count==0){
                count=1;
                maj = nums[i]; // assume
            }else if(nums[i]== maj){
                count++;
            }else{
                count--;
            }
        }
        return maj;
    }
};

/*
#include<unordered_map>
class Solution {
public:
   int majorityElement(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin(), nums.end());
       return nums[n/2];

/*
////. time complexity is O(n) and space complexity O(n/2) ~ O(n);
 
        unordered_map<int, int> maj;
        for(int i=0;i<nums.size();i++){
            if(maj[nums[i]]>0){
                maj[nums[i]]++;
                continue;
            }
             maj[nums[i]]=1;
        }

        int max=0;
        int index=0;
        for(int i=0;i<nums.size();i++){
             if(maj[nums[i]]>max){
                 max=maj[nums[i]];
                 index = i;
             }
        }
        return nums[index];
        */
    }

};
*/