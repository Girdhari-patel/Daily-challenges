class Solution
{
    public:
        int maxSum(int n)
        {
            //code here.
            if(n<12)return n;
            int sum=0;
            int a = maxSum(n/2);
            int b = maxSum(n/3);
            int c = maxSum(n/4);
            sum = max(sum, a+b+c);
            
            return sum;
        }
};