/*
229. Majority Element II
 
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]
 

Constraints:

1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 

Follow up: Could you solve the problem in linear time and in O(1) space?
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1=0;
        int maj1 = NULL;

        int count2=0;
        int maj2 = NULL;

        for(int i=0;i<n;i++){
            if(nums[i]==maj1){
                count1++;
            }else if(nums[i]==maj2){
                count2++;
            }else if(count1==0){
                maj1=nums[i];
                count1=1;
            }else if(count2==0){
                maj2=nums[i];
                count2=1;
            }else{
                count1--;
                count2--;
            }
        }
        //varification
        vector<int>result;
        int freq1=0;
        int freq2=0;
        for(int &num:nums){
            if(num==maj1){
                freq1++;
            }else if(num==maj2){
                freq2++;
            }
        }
        
        if(freq1>floor(n/3)){
            result.push_back(maj1);
        }
        if(freq2>floor(n/3)){
            result.push_back(maj2);
        }

        return result;

    }
};