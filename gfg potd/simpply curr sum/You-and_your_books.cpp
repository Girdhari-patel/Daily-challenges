class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long ans=0;
        long long currSum =0;
        
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                currSum+=arr[i];
            }else{
                currSum = 0;
            }
            ans = max(ans, currSum);
        }
        
        return ans;
    }
};